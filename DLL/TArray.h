#pragma once

#include <algorithm>

// An array with capacity at power of 2
template<typename T>
class TArray
{
private:
	size_t m_NumElements;
	T* m_Array;

	// ceil of number's power of 2
	// ex: 3 -> 4, 12 -> 16
	static inline size_t Get2Ceil(size_t n) {
		n--;
		n |= n >> 1;
		n |= n >> 2;
		n |= n >> 4;
		n |= n >> 8;
		n |= n >> 16;
		return n + 1;
	}

public:
	TArray() : m_NumElements(0), m_Array(nullptr) {}
	~TArray() {
		if (m_Array)
			delete[] m_Array;
	}

	inline size_t GetNumElements() const { return m_NumElements; }

	inline T* GetData() { return m_Array; }

	void Resize(size_t numElements) {
		if (numElements == m_NumElements)
			return;

		size_t capacity = Get2Ceil(numElements);

		// no shrinking
		if (capacity <= Get2Ceil(m_NumElements))
			return;

		T* tempArray = new T[capacity];
		std::copy(m_Array, m_Array + m_NumElements, tempArray);

		if (m_Array)
			delete[] m_Array;

		m_Array = tempArray;
	}

	inline T& Back() {
		return m_Array[m_NumElements - 1];
	}

	inline void PushBack(const T& element) {
		Resize(m_NumElements + 1);
		m_Array[m_NumElements++] = element;
	}

	// Inserts an uninitialized element at the end and returns it
	inline T& InsertEmptyBack() {
		Resize(m_NumElements + 1);
		return m_Array[m_NumElements++];
	}

	inline T& operator[](size_t i) {
		if (i >= m_NumElements) {
			Resize(i + 1);
			m_NumElements = i + 1;
		}

		return m_Array[i];
	}

	TArray<T>& operator=(const TArray<T>& rhs) {
		if (m_NumElements != rhs.m_NumElements) {
			size_t capacity = Get2Ceil(rhs.m_NumElements);

			if (m_Array)
				delete[] m_Array;

			m_Array = new T[capacity];
		}

		m_NumElements = rhs.m_NumElements;
		std::copy(rhs.m_Array, rhs.m_Array + m_NumElements, m_Array);

		return *this;
	}
};