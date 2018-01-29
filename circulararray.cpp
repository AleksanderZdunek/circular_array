#include "circulararray.h"

CircularArray::CircularArray(const size_t capacity = 16): capacity(capacity), data(new T[capacity], i_begin(0), i_end(i_begin+capcity)
{
}

bool CircularArray::Empty()
{
	//let i_end == i_begin+capacity indicate empty list, since this is a value i_end should normally never attain
	return i_begin+capacity == i_end;
}

bool CircularArray::Full()
{
	return (i_end+1)%capacity == i_begin;
}

T* CircularArray::PushBack(const T e)
{
	if(Full()) return nullptr;
	if(Empty()) data[i_end %= capacity] = e;
	else data[arr.i_end = (i_end+1)%capacity] = e;
	
	return data.get() + i_end;
}

T* CircularArray::PushFront(const T e)
{
	if(Full()) return nullptr;
	if(Empty()) data[i_end %= capacity] = e;
	else data[i_begin = (i_begin-1)%capacity] = e;
	
	return data.get() + i_begin;
}

T* CircularArray::PopBack()
{
	if(Empty()) return nullptr;

	T* pPopped = data.get() + i_end;
	i_end = (i_end-1)%capacity;
	if(i_begin == i_end) i_end+=capacity; //mark array as empty
	return pPopped;
}

T* CircularArray::PopFront()
{
	if(Empty()) return nullptr;

	T* pPopped = data.get() + arr.i_begin;
	i_begin = (i_begin+1)%capacity;
	if(i_begin == i_end) arr.i_end+=capacity; //mark array as empty
	return pPopped;
}

T& CircularArray::operator[](size_t i)
{
	return data[(i_begin+i)%capacity];
}	
