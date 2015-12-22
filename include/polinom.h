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
	 Polinom& operator-=( Polinom &q);
	 Polinom& operator=( Polinom &q);
	 Polinom& MultiNum(double num);

};

