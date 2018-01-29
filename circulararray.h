#pragma once

#include <memory>

typedef int T;

class CircularArray
{
public:
	CircularArray(const size_t capacity);
	bool Empty();
	bool Full();
	T* PushBack(const T e);
	T* PushFront(const T e);
	T* PopBack();
	T* PopFront();
	T& operator[](size_t i);
	
	friend void DebugPrint(const CircularArray& arr);
private:
	std::unique_ptr<int[]> data;
	const size_t capacity;
	size_t i_begin;
	size_t i_end;
}