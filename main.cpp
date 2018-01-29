#include <iostream>
#include "circulararray.h"

void DebugPrint(const CircularArray& arr)
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

	CircularArray ring;
	
	std::cout << "Size: " << ring.Size() << " Expect: 0\n";
	
	//for(int i=0; i<capacity; i+=2) PushBack(ring, i), PushFront(ring, i+1);
	for(int i=0; i<ring.Capacity(); i++) ring.PushBack(i);
	DebugPrint(ring);
	
	std::cout << "Size: " << ring.Size() << " Expect: 16\n";
	
	ring.PopFront(), ring.PopFront(), ring.PopFront();
	DebugPrint(ring);
	std::cout << "Size: " << ring.Size() << " Expect: 13\n";
	
	ring.PushBack(55), ring.PushBack(56),  ring.PushBack(57), ring.PushBack(58);
	
	DebugPrint(ring);
	
	for(int i=0; i<ring.Capacity(); i++) ring.PopBack();
	std::cout << "Size: " << ring.Size() << " Expect: 0\n";
	for(int i=0; i<ring.Capacity(); i++) ring.PushBack(i);
	std::cout << "Size: " << ring.Size() << " Expect: 16\n";
	
	DebugPrint(ring);

	return 0;
}
