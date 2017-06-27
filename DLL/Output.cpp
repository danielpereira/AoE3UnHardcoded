/*#include "stdafx.h"
#include "UHC.h"
#include <stdio.h>

struct syscall_t {
	DWORD retType;
	LPCSTR name;
	DWORD fPtr;
	DWORD paramCount;
	DWORD params[16];
	LPCSTR comment;
} syscall;

LPCSTR XSTypeName(DWORD type) {
	LPCSTR str;
	switch (type) {
	case XSVoid:
		str = "void";
		break;
	case XSInteger:
		str = "int";
		break;
	case XSFloat:
		str = "float";
		break;
	case XSBool:
		str = "bool";
		break;
	case XSString:
		str = "string";
		break;
	case XSVector:
		str = "vector";
	}

	return str;
}

extern "C" void __stdcall DumpSyscallRegister(LPCSTR name, DWORD fPtr, DWORD retType) {
	syscall.name = name;
	syscall.fPtr = fPtr;
	syscall.retType = retType;
	syscall.paramCount = 0;
}

extern "C" void __stdcall DumpSyscallParamInteger() {
	syscall.params[syscall.paramCount++] = XSInteger;
}

extern "C" void __stdcall DumpSyscallParamFloat() {
	syscall.params[syscall.paramCount++] = XSFloat;
}

extern "C" void __stdcall DumpSyscallParamBool() {
	syscall.params[syscall.paramCount++] = XSBool;
}

extern "C" void __stdcall DumpSyscallParamString() {
	syscall.params[syscall.paramCount++] = XSString;
}

extern "C" void __stdcall DumpSyscallParamVector() {
	syscall.params[syscall.paramCount++] = XSVector;
}

#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

extern "C" void __stdcall DumpSyscallEnd() {
	ifstream ifs;
	ifs.open("C:\\Users\\Cliff\\Desktop\\syscalls.cpp");

	string search = syscall.name;
	search += "_t";

	string line;
	bool exists = false;

	if (ifs.is_open()) {
		while (getline(ifs, line)) {
			if (line.find(search, 0) != string::npos) {
				exists = true;
				break;
			}
		}
		ifs.close();
	}

	if (!exists) {
		FILE* f;
		fopen_s(&f, "C:\\Users\\Cliff\\Desktop\\syscalls.h", "a");

		LPCSTR comment = strchr(syscall.comment, ':');
		LPCSTR ptr = strstr(syscall.comment, syscall.name);
		DWORD name_count = 0;
		string s, names[16];
		stringstream ss;

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
		fprintf_s(f, "typedef %s (*%s_t)(", XSTypeName(syscall.retType), syscall.name);
		if (syscall.paramCount > 0) {
			DWORD i;
			for (i = 0; i < syscall.paramCount - 1; i++) {
				if (i < name_count)
					fprintf_s(f, "%s %s, ", XSTypeName(syscall.params[i]), names[i].c_str());
				else
					fprintf_s(f, "%s, ", XSTypeName(syscall.params[i]));
			}
			if (i < name_count)
				fprintf_s(f, "%s %s", XSTypeName(syscall.params[i]), names[i].c_str());
			else
				fprintf_s(f, "%s", XSTypeName(syscall.params[i]));
		}
		fprintf_s(f, ");\n//%s\nextern const %s_t %s;\n\n", comment + 1, syscall.name, syscall.name);
		fclose(f);

		fopen_s(&f, "C:\\Users\\Cliff\\Desktop\\syscalls.cpp", "a");
		fprintf_s(f, "const %s_t %s = (%s_t)0x%x;\n", syscall.name, syscall.name, syscall.name, syscall.fPtr);
		fclose(f);
	}
}

extern "C" void __stdcall DumpSyscallComment(LPCSTR comment) {
	syscall.comment = comment;
}*/