#include <iostream>

typedef int T;

const size_t capacity = 16;

struct CircularArray
{
	T data[capacity];
	size_t i_begin = 0;
	size_t i_end = i_begin+capacity; //let i_end == i_begin+capacity indicate empty list, since this is a value i_end should normally never attain
};

/**
	TODO: Proper doxygen
	Convert circular array index to linear data array index
	
	Argument is circular array index 
	
	Returns linear data array index
*/
size_t Index(const CircularArray& arr, size_t circularIndex)
{
	return (arr.i_begin+circularIndex)%capacity;
}

/**
	For completeness sake.
	Convert linear data index to circular index.
	
	TODO: doxygen
*/
size_t Index2(const CircularArray& arr, size_t linearIndex)
{
	return (linearIndex-arr.i_begin)%capacity;
}

/**
	Returns an element pointer from an circular array index
*/
T* PointerFromIndex(const CircularArray& arr, size_t i)
{
	return const_cast<T*>(arr.data+Index(arr, i));
}

bool Empty(const CircularArray& arr)
{
	return capacity == arr.i_end-arr.i_begin;
}

bool Full(const CircularArray& arr)
{
	return (arr.i_end+1)%capacity == arr.i_begin;
}

T* PushBack(CircularArray& arr, const T e)
{
	if(Full(arr)) return nullptr;
	if(Empty(arr)) arr.data[arr.i_end %= capacity] = e;
	else arr.data[arr.i_end = (arr.i_end+1)%capacity] = e;
	
	return arr.data + arr.i_end;
}


T* PushFront(CircularArray& arr, const T e)
{
	if(Full(arr)) return nullptr;
	if(Empty(arr)) arr.data[arr.i_end %= capacity] = e;
	else arr.data[arr.i_begin = (arr.i_begin-1)%capacity] = e;
	
	return arr.data + arr.i_begin;
}

T* PopBack(CircularArray& arr)
{
	if(Empty(arr)) return nullptr;

	T* pPopped = arr.data + arr.i_end;
	arr.i_end = (arr.i_end-1)%capacity;
	if(arr.i_begin == arr.i_end) arr.i_end+=capacity; //mark array as empty
	return pPopped;
}

T* PopFront(CircularArray& arr)
{
	if(Empty(arr)) return nullptr;

	T* pPopped = arr.data+arr.i_begin;
	arr.i_begin = (arr.i_begin+1)%capacity;
	if(arr.i_begin == arr.i_end) arr.i_end+=capacity; //mark array as empty
	return pPopped;
}

void DebugPrint(const CircularArray& arr)
{
	std::cout<<"data:";
	for(int i=0; i<capacity; i++) std::cout << " " << arr.data[i];
	std::cout<<"\nidxd:";
	for(int i=0; i<capacity; i++) std::cout << " " << *PointerFromIndex(arr, i); //std::cout << " " << arr.data[Index(arr,i)];
	std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
	std::cout << "circular_array" << std::endl;

	CircularArray ring;
	
	for(int i=0; i<capacity; i+=2) PushBack(ring, i), PushFront(ring, i+1);
	
	DebugPrint(ring);
	
	PopBack(ring), PopBack(ring);
	
	PushFront(ring, 33), PushFront(ring, 44), PushFront(ring, 55);
	
	DebugPrint(ring);

	return 0;
}

void stashed()
{
	CircularArray ring;
	
	for(int i=0; i<capacity; i++) PushBack(ring, i);

	DebugPrint(ring);
	
	std::cout << "PopFront()\n";
	PopFront(ring);
	DebugPrint(ring);
	
	std::cout << "PushBack(16)\n";
	PushBack(ring, 16);
	DebugPrint(ring);
	
	
	for(int i=0; i<capacity-10; i++) PopFront(ring);
	for(int i=0; i<capacity; i++) PushBack(ring, i+20);
	DebugPrint(ring);
}


void stashed2()
{
	CircularArray ring;
	
	for(int i=0; i<capacity; i++) PushBack(ring, i);

	for(int i=0; i<=5; i++) PopFront(ring);

	DebugPrint(ring);
	
	for(int i=0; i<capacity; i++) std::cout << " " << Index(ring, i);
	std::cout << std::endl;
	for(int i=0; i<capacity; i++) std::cout << " " << Index2(ring, i);
	
	std::cout << std::endl;
}
