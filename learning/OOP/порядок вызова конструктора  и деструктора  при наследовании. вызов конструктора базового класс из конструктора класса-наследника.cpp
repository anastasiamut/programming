//порядок вызова конструктора  и деструктора  при наследовании. вызов конструктора базового класс из конструктора класса-наследника


#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class A
{
public:
	A()
	{
		cout << "Constructor A" << endl;
	}
	~A()
	{
		cout << "Destructor A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "Constructor B" << endl;
	}
	~B()
	{
		cout << "Destructor B" << endl;
	}

};

class C:public B
{
public:
	C()
	{
		cout << "constructor C" << endl;
	}
	~C()
	{
		cout << "Destructor C" << endl;
	}
};
int main()
{
	A a;
	cout << endl << endl;

	B b;
	cout << endl << endl;

	C c;

	cout << endl << endl;
	

}



