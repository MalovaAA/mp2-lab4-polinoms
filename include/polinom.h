// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов
#pragma once
#include "monom.h"
#include <iostream>
#include "List.h"

using namespace std;

class Polinom: public List<Monom>{

public:
	 Polinom();
	 Polinom(Polinom& p);
	 Polinom& operator+=(Polinom &q);
	 Polinom& operator-=(Polinom &q);
	 Polinom& operator=(Polinom &q);
	 Polinom& MultiNum(double num);

};

Polinom::Polinom()
{
	Monom temp(0, -1);
	headNode = new Node<Monom>;
	headNode->Set(temp);
	headNode->SetNextNode(headNode);
}

Polinom::Polinom(Polinom& p)
{
	Monom temp(0, -1);
	headNode = new Node<Monom>;
	headNode->Set (temp);
	headNode->SetNextNode(headNode);

	for (int i = 0; i < p.GetLength(); i++)
	{

		Push(p.GetCurrData(i));
	};

}

Polinom& Polinom::operator+=(Polinom &q)
{
	Reset();
	q.Reset();

	while (currNode != headNode || q.currNode != q.headNode)
	{
		if (currNode->Get() < q.currNode->Get()) 
		{
			Push(q.currNode->Get());           
			q.GoNext();

		} 
		else if (currNode->Get() == q.currNode->Get())
		{
			Monom temp(currNode->Get().coef + q.currNode->Get().coef, currNode->Get().power);

			currNode->Set(temp);

			if (currNode->Get().coef == 0)
			{
				DeleteCurr();  
				q.GoNext();
			}
			else
			{
				q.GoNext();
				GoNext();
			};
		} 
		else 
		{
			GoNext();
		}
	};

	return *this;
}

Polinom& Polinom::operator-=(Polinom &q)
{
	return (*this) += q.MultiNum(-1);
}

Polinom& Polinom::operator=(Polinom &q)
{
	this->DeleteList();

	Monom temp(0, -1);
	headNode = new Node<Monom>;
	headNode->Set (temp);
	headNode->SetNextNode(headNode);

	for (int i = 0; i < q.GetLength(); i++)
	{
		Push(q.GetCurrData(i));
	};

	return *this;
}
Polinom& Polinom::MultiNum(double num)
{
	currNode = headNode->GetNextNode();
	while (currNode != headNode)
	{
		Monom temp(num*currNode->Get().coef, currNode->Get().power);
		currNode->Set(temp);
		currNode = currNode->GetNextNode();
	};

	return *this;
}
 
