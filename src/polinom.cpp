#include "polinom.h"

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

	for (int i = 0; i < p.GetLength(); i++) // засенить а while (curr!=headNode)
	{
		// Insert сразу после curr
		Push(p.GetCurrData(i));
	}

}

Polinom& Polinom::operator+=(Polinom &q)
{
	Reset();
	q.Reset();

	while (currNode != headNode || q.currNode != q.headNode)
	{
		if (currNode->Get() < q.currNode->Get()) 
		{
			// Insert сразу после curr
			Push(q.currNode->Get());           
			q.GoNext();

		} 
		else if (currNode->Get() == q.currNode->Get())
		{
			Monom temp(currNode->Get().coef + q.currNode->Get().coef, currNode->Get().power);

			currNode->Set(temp);

			if (abs(currNode->Get().coef) > 1e-12) 
			{
				DeleteCurr();  
				q.GoNext();
			}
			else
			{
				q.GoNext();
				GoNext();
			}
		} 
		else 
		{
			GoNext();
		}
	}

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
		// Insert сразу после curr
		Push(q.GetCurrData(i));
	}

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
	}

	return *this;
}
 
