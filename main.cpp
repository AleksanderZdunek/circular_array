#include <iostream>

typedef int T;

const size_t capacity = 16; //capacity should be greater than 1. If capacity == 1 Empty() and Full() will both return true and push and pop will always fail.

struct CircularArray
{
	T data[capacity];
	T* beginning = data;
	T* end = data;
};

//T* PointerFromIndex(const CircularArray& arr, size_t i)
T* PointerFromIndex(CircularArray& arr, size_t i)
{
	return (arr.beginning+i-arr.data)%capacity + arr.data;
}

size_t IndexFromPointer(const CircularArray& arr, const T* p)
{
	return (p-arr.beginning)%capacity;
}

bool Empty(const CircularArray& arr)
{
	return arr.beginning == arr.end;
}

bool Full(const CircularArray& arr)
{
	return ((arr.end+1 - arr.data)%capacity + arr.data) == arr.beginning;
}

T* PushBack(CircularArray& arr, const T& e)
{
	if(Full(arr)) return nullptr;

	*(arr.end=((arr.end+1-arr.data)%capacity+arr.data)) = e;
	return arr.end;
}

T* PushFront(CircularArray& arr, const T& e)
{
	if(Full(arr)) return nullptr;

	*(arr.beginning=((arr.beginning-1-arr.data)%capacity+arr.data)) = e;
	return arr.beginning;
}

T* PopBack(CircularArray& arr)
{
	if(Empty(arr)) return nullptr;

	T* old = arr.end;
	arr.end = (arr.end-1-arr.data)%capacity+arr.data;
	return old;
}

T* PopFront(CircularArray& arr)
{
	if(Empty(arr)) return nullptr;

	T* old = arr.beginning;
	arr.beginning = (arr.beginning+1-arr.data)%capacity+arr.data;
	return old;
}

void DebugPrint(CircularArray& arr)
{
	std::cout<<"data:";
	for(int i=0; i<capacity; i++) std::cout << " " << arr.data[i];
	std::cout<<"\nidxd:";
	for(int i=0; i<capacity; i++) std::cout << " " << *PointerFromIndex(arr, i);
	std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
	std::cout << "circular_array" << std::endl;

	CircularArray ca;

	for(int i=0; i<capacity; i++) PushBack(ca, i);

	DebugPrint(ca);

	return 0;
}
