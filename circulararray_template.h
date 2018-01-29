#pragma once

#include <memory>

template<typename T>
class CircularArray
{
public:
	CircularArray(const size_t capacity = 16);
	bool Empty();
	bool Full();
	size_t Capacity();
	size_t Size();
	T* PushBack(const T e);
	T* PushFront(const T e);
	T* PopBack();
	T* PopFront();
	T& operator[](size_t i) const;

	template<typename U>
	friend void DebugPrint(const CircularArray<U>& arr);
private:
	std::unique_ptr<T[]> data;
	const size_t capacity;
	size_t i_begin;
	size_t i_end;
};

template<typename T>
CircularArray<T>::CircularArray(const size_t capacity): capacity(capacity), data(new T[capacity]), i_begin(0), i_end(i_begin+capacity)
{
}

template<typename T>
bool CircularArray<T>::Empty()
{
	//let i_end == i_begin+capacity indicate empty list, since this is a value i_end should normally never attain
	return i_begin+capacity == i_end;
}

template<typename T>
bool CircularArray<T>::Full()
{
	return (i_end+1)%capacity == i_begin;
}

template<typename T>
size_t CircularArray<T>::Capacity()
{
	return capacity;
}

template<typename T>
size_t CircularArray<T>::Size()
{
	if(Empty()) return 0;

	//calculate circular index of last element, and add 1
	return (i_end-i_begin)%capacity + 1;
}

template<typename T>
T* CircularArray<T>::PushBack(const T e)
{
	if(Full()) return nullptr;
	if(Empty()) data[i_end %= capacity] = e;
	else data[i_end = (i_end+1)%capacity] = e;

	return data.get() + i_end;
}

template<typename T>
T* CircularArray<T>::PushFront(const T e)
{
	if(Full()) return nullptr;
	if(Empty()) data[i_end %= capacity] = e;
	else data[i_begin = (i_begin-1)%capacity] = e;

	return data.get() + i_begin;
}

template<typename T>
T* CircularArray<T>::PopBack()
{
	if(Empty()) return nullptr;

	T* pPopped = data.get() + i_end;
	i_end = (i_end-1)%capacity;
	if(i_begin == i_end) i_end+=capacity; //mark array as empty
	return pPopped;
}

template<typename T>
T* CircularArray<T>::PopFront()
{
	if(Empty()) return nullptr;

	T* pPopped = data.get() + i_begin;
	i_begin = (i_begin+1)%capacity;
	if(i_begin == i_end) i_end+=capacity; //mark array as empty
	return pPopped;
}

template<typename T>
T& CircularArray<T>::operator[](size_t i) const
{
	return data[(i_begin+i)%capacity];
}
