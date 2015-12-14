#pragma once


#include <iostream>

using namespace std;

template <class T>

class Node 
{
protected:
	T data;//значение в звене
	Node<T>* next;//указатель на след звено

public:

	void SetNextNode(Node<T>* _nextNode)//записать указатель на след звено
    {
        next = _nextNode;
    }

	Node<T>* GetNextNode ()//получить указатель
	{
		return next;
	}

	void Set (T _data)//записать значение в звено
	{
		data = _data;
	}

	T Get ()
	{
		return data;//получить значение звена
	}

};