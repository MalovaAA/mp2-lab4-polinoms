// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������
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
	 Polinom& operator-=( Polinom &q);
	 Polinom& operator=( Polinom &q);
	 Polinom& MultiNum(double num);

};

