#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>

class List {
protected:
	Node<T>* headNode;//указатель на фиктивную голову списка
	Node<T>* currNode;//указатель на текущее звено 
	Node<T>* prevNode;//указатель на предыдущее звено 
	Node<T>* newNode;//указатель на какое-то новое звено  

	int length;//длина списка

public:
	List ();//конструктор
	void Push (T data);//добавить элемент       
	void DeleteCurr ();//удалить элемент     
	Node<T>* Search (T elem);//поиск элемента 
	bool IsEmpty();//проверка на пустоту списка
	int GetLength();//вернуть длину списка
	void DeleteList();//очистить список
	void GoNext();//перейти к след звену
	void Reset();//вернуть в начало
	T GetCurrData(int pos);

};

template <class T>
List<T>::List()
{

	headNode = new Node<T>();
	headNode->SetNextNode(headNode);
    length = 0;
}

template <class T>
void List<T>::Push (T data)
{
                
	newNode = new Node<T>();   
	newNode->Set(data);

	currNode = headNode->GetNextNode();     
	prevNode = headNode;    

	while (data < currNode->Get())  
	{
		prevNode = currNode;                   
		currNode = currNode->GetNextNode();   
	};
		
	newNode->SetNextNode(currNode);  
	prevNode->SetNextNode(newNode); 

	prevNode = prevNode->GetNextNode();

	++length;
}
template <class T>
void List<T>::DeleteCurr ()
{
	if (!IsEmpty())
	{
		prevNode->SetNextNode(currNode->GetNextNode());
		delete currNode;

		currNode = prevNode->GetNextNode();
            
		--length;
	};
}

template <class T>
void List<T>::GoNext()
{
	prevNode = currNode;
	currNode = currNode->GetNextNode();
}

template <class T>
void List<T>::Reset()
{
	prevNode = headNode;
	currNode = headNode->GetNextNode();
}

template <class T>
Node<T>* List<T>::Search (T elem)
{
	if (!IsEmpty())
	{
	   currNode = headNode->GetNextNode();
	   while (currNode->Get() != elem)
	   {
		  prevNode = currNode;
		  currNode = currNode->GetNextNode();
	   };
	
	   return currNode;
	};
}

template <class T>
bool List<T>::IsEmpty()
{
	if (length == 0) return true;
	return false;
}

template <class T>
int List<T>::GetLength()
{
	return length;
}

template <class T>
T List<T>::GetCurrData(int pos)
{
	currNode = headNode->GetNextNode();
	prevNode = currNode;

	for (int i = 0; i < pos; i++) 
	{
		prevNode = currNode;                   
		currNode = currNode->GetNextNode();    
	};
	
	return currNode->Get();
}

template <class T>
void List<T>::DeleteList()
{
	currNode = headNode->GetNextNode();

	while (currNode != headNode)
	{
		prevNode = currNode; 
		currNode = currNode->GetNextNode();   
		delete prevNode;
	};

	delete currNode;
	length = 0;
}
