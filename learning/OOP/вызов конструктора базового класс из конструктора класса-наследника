//вызов конструктора базового класс из конструктора класса-наследника


#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class A
{
public:
	A()
	{
		msg = "Empty";
	}

	A(string msg, int value)
	{
		this->msg = msg;
	}

	A(string msg)
	{
		this->msg = msg;
	}

	void PrintMsg()
	{
		cout << msg << endl;
	}

private:
	string msg;
};

class B : public A
{
public:
	B():A("our new message")
	{

	}

};


int main()
{

	B b;
	b.PrintMsg();


}




