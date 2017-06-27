#include "stdafx.h"
#include "UHC.h"
#include <stdio.h>

struct syscall_t {
	DWORD retType;
	LPCSTR name;
	DWORD fPtr;
	DWORD paramCount;
	DWORD paramTypes[16];
	union default_param_t {
		int Integer;
		float Float;
		BOOL Boolean;
		LPCSTR String;
		const float* Vector;
	} params[16];
	LPCSTR comment;
} syscall;

extern "C" void __stdcall DumpSyscallRegister(LPCSTR name, DWORD fPtr, DWORD retType) {
	syscall.name = name;
	syscall.fPtr = fPtr;
	syscall.retType = retType;
	syscall.paramCount = 0;
}

extern "C" void __stdcall DumpSyscallParam(DWORD type, LPCVOID defaultVal) {
	syscall.paramTypes[syscall.paramCount] = type;
	switch (type)
	{
	case SyscallInteger:
		syscall.params[syscall.paramCount++].Integer = *(int*)defaultVal;
		break;
	case SyscallFloat:
		syscall.params[syscall.paramCount++].Float = *(float*)defaultVal;
		break;
	case SyscallBool:
		syscall.params[syscall.paramCount++].Boolean = *(BOOL*)defaultVal;
		break;
	case SyscallString:
		syscall.params[syscall.paramCount++].String = (LPCSTR)defaultVal;
		break;
	case SyscallVector:
		syscall.params[syscall.paramCount++].Vector = (const float*)defaultVal;
	}
}

using namespace std;

string sHeaderFPtr = "";
string sCppFPtr = "";
string sHeader = "";
string sCpp = "";

string __fastcall PrintDefaultParam(DWORD type, const syscall_t::default_param_t& defaultVal) {
	ostringstream ossConv;

	switch (type)
	{
	case SyscallInteger:
		ossConv << defaultVal.Integer;
		return ossConv.str();
	case SyscallFloat:
		ossConv << defaultVal.Float;
		return ossConv.str();
	case SyscallBool:
		if (defaultVal.Boolean)
			return string("true");
		else
			return string("false");
	case SyscallString:
		ossConv << '\"' << defaultVal.String << '\"';
		return ossConv.str();
	case SyscallVector:
		ossConv << "vector("
			<< defaultVal.Vector[0] << ", " << defaultVal.Vector[1] << ", " << defaultVal.Vector[2]
			<< ')';
		return ossConv.str();
	}

	return string();
}

extern "C" void __stdcall DumpSyscallEnd() {
	static vector<DWORD> fPtrs;
	LPCSTR typeNames[33];

	typeNames[SyscallVoid] = "void";
	typeNames[SyscallInteger] = "int";
	typeNames[SyscallFloat] = "float";
	typeNames[SyscallBool] = "bool";
	typeNames[SyscallString] = "string";
	typeNames[SyscallVector] = "vector";

	if (!binary_search(fPtrs.begin(), fPtrs.end(), syscall.fPtr)) {
		LPCSTR comment = strchr(syscall.comment, ':');
		LPCSTR ptr = strstr(syscall.comment, syscall.name);
		DWORD name_count = 0;
		string s, names[16];

		// analyze the comment and get argument names
		if (ptr && comment) {
			LPCSTR beg = ptr + strlen(syscall.name);
			s = beg;
			s = s.substr(0, comment - beg);
			replace(s.begin(), s.end(), '<', ' ');
			replace(s.begin(), s.end(), '>', ' ');
			replace(s.begin(), s.end(), '[', ' ');
			replace(s.begin(), s.end(), ']', ' ');
			replace(s.begin(), s.end(), '{', ' ');
			replace(s.begin(), s.end(), '}', ' ');
			replace(s.begin(), s.end(), '(', ' ');
			replace(s.begin(), s.end(), ')', ' ');
			replace(s.begin(), s.end(), '\"', ' ');
			replace(s.begin(), s.end(), ',', ' ');

			stringstream ss(s);
			string temp;
			while (ss >> temp) {
				if (strcmp(temp.c_str(), "void") != 0 &&
					strcmp(temp.c_str(), "int") != 0 &&
					strcmp(temp.c_str(), "float") != 0 &&
					strcmp(temp.c_str(), "bool") != 0 &&
					strcmp(temp.c_str(), "string") != 0 &&
					strcmp(temp.c_str(), "vector") != 0 &&
					strcmp(temp.c_str(), "long") != 0)
					names[name_count++] = temp;
			}
		}

		if (!comment)
			comment = syscall.comment;
		else
			comment++;

		std::string args;
		std::string argsWithNames;
		std::string argsWithNamesAndDefaults;
		std::string argsCall;
		char ch = 'a'; // used for unnamed variables

		args += '(';
		argsWithNames += '(';
		argsWithNamesAndDefaults += '(';
		argsCall += '(';

		if (syscall.retType == SyscallVector) {
			args += "vector";
			argsWithNames += "vector result";
			argsWithNamesAndDefaults += "vector result";
			argsCall += "result";

			if (syscall.paramCount > 0) {
				args += ", ";
				argsWithNames += ", ";
				argsWithNamesAndDefaults += ", ";
				argsCall += ", ";
			}
		}

		for (DWORD i = 0; i < syscall.paramCount; i++) {
			args += typeNames[syscall.paramTypes[i]];
			argsWithNames+= typeNames[syscall.paramTypes[i]];
			argsWithNamesAndDefaults += typeNames[syscall.paramTypes[i]];

			if (i < name_count) {
				argsWithNames += ' ';
				argsWithNames += names[i].c_str();

				argsWithNamesAndDefaults += ' ';
				argsWithNamesAndDefaults += names[i].c_str();

				argsCall += names[i].c_str();
			}
			else { // no name for this argument, use alphabets starting from a
				argsWithNames += ' ';
				argsWithNames += ch + i - name_count;

				argsWithNamesAndDefaults += ' ';
				argsWithNamesAndDefaults += ch + i - name_count;

				argsCall += ch + i - name_count;
			}

			argsWithNamesAndDefaults+= " = ";
			argsWithNamesAndDefaults += PrintDefaultParam(syscall.paramTypes[i], syscall.params[i]);

			if (i < syscall.paramCount - 1) {
				args += ", ";
				argsWithNames += ", ";
				argsWithNamesAndDefaults += ", ";
				argsCall += ", ";
			}
		}

		args += ')';
		argsWithNames += ')';
		argsWithNamesAndDefaults += ')';
		argsCall += ')';

		ostringstream oss;

		oss << "//" << comment << endl <<
			"extern " << typeNames[syscall.retType]  << "(*const " << syscall.name << ')' << argsWithNames << ';' << endl << endl;
		sHeaderFPtr += oss.str();
		oss.clear();
		oss.str(string());

		oss << typeNames[syscall.retType] << "(*const " << syscall.name << ')' << args <<
			" = reinterpret_cast<" << typeNames[syscall.retType] << "(*)" << args << ">(0x" << hex << syscall.fPtr << ");" << endl;
		sCppFPtr += oss.str();
		oss.clear();
		oss.str(string());

		oss << "//" << comment << endl << typeNames[syscall.retType] << ' ' << syscall.name << argsWithNamesAndDefaults << ';' << endl << endl;
		sHeader += oss.str();
		oss.clear();
		oss.str(string());

		oss << typeNames[syscall.retType] << ' ' << syscall.name << argsWithNames << " {" << endl << "\t";

		if (syscall.retType != SyscallVoid)
			oss << "return ";
		oss	<< "reinterpret_cast<" << typeNames[syscall.retType] << "(*)" << args << ">(0x" << hex << syscall.fPtr << ")" << argsCall << ';' << endl
			<< '}' << endl << endl;
		sCpp += oss.str();

		fPtrs.push_back(syscall.fPtr);
		
		// insertion sort
		for (auto i = fPtrs.begin(); i != fPtrs.end(); i++)
			rotate(upper_bound(fPtrs.begin(), i, *i), i, i + 1);
	}
}

extern "C" void __stdcall DumpSyscallComment(LPCSTR comment) {
	syscall.comment = comment;
}

// .dmp.txt
/*void DumpConstants() {
	ifstream ifs;
	FILE* f, *fc;
	ifs.open("C:\\Users\\Cliff\\Desktop\\constants.txt");
	fopen_s(&f, "C:\\Users\\Cliff\\Desktop\\constants.h", "w");
	fopen_s(&fc, "C:\\Users\\Cliff\\Desktop\\constants.cpp", "w");

	string line;
	while (getline(ifs, line)) {
		const char* ptr = strchr(line.c_str(), '$');
		CHAR lpName[256], lpValue[8];
		lstrcpynA(lpName, ptr + 1, strchr(ptr, ' ') - ptr);
		ptr = strstr(ptr, "Value=") + 5;
		lstrcpynA(lpValue, ptr + 1, strchr(ptr, '.') - ptr);
		fprintf_s(f, "extern const int %s;\n", lpName);
		fprintf_s(fc, "const int %s = %s;\n", lpName, lpValue);
	}
	fclose(f);
	fclose(fc);
}*/