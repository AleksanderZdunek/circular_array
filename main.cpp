#include <iostream>
#include "circulararray_template.h"

template<typename T>
void DebugPrint(const CircularArray<T>& arr)
{
	std::cout<<"data:";
	for(int i=0; i<arr.capacity; i++) std::cout << " " << arr.data[i];
	std::cout<<"\nidxd:";
	for(int i=0; i<arr.capacity; i++) std::cout << " " << arr[i]; //std::cout << " " << arr.data[Index(arr,i)];
	std::cout<<std::endl;
}

int main(int argc, char* argv[])
{
	std::cout << "circular_array" << std::endl;

	CircularArray<int> ring(3);

	DebugPrint(ring);
	std::cout <<"Size: " << ring.Size() << "\n" << std::endl;

	for(int i=0; i<ring.Capacity(); i++) ring.PushBack(i);
	DebugPrint(ring);

	std::cout <<"Size: " << ring.Size() << "\n" << std::endl;

	ring.PopFront();
	DebugPrint(ring);
	std::cout <<"Size: " << ring.Size() << "\n" << std::endl;

	ring.PushBack(55);

	DebugPrint(ring);
	std::cout <<"Size: " << ring.Size() << "\n" << std::endl;

	ring.PopFront();
	DebugPrint(ring);
	std::cout <<"Size: " << ring.Size() << "\n" << std::endl;

	ring.PushFront(56);
	ring.PushFront(57);
	DebugPrint(ring);
	std::cout <<"Size: " << ring.Size() << "\n" << std::endl;

	return 0;
}
