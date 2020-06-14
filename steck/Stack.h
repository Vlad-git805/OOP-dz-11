#pragma once
template<class T>
class Stack
{
	T *data;
	int maxSize;
	int topIndex;

public:
	Stack();
	Stack(int size);
	~Stack();			

	bool Push(T elem);
	T Pop();
	T Peek();
	int GetCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
	bool IsInfinity() const;
	void Clear();
};