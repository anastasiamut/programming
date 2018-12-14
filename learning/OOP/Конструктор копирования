// Конструктор копирования

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class MyClass
{
public:
	int* data;

	MyClass(int size)
	{
		this->size = size;
		this->data = new int[size];

		for(int i=0; i<size; i++)
		{
			data[i] = i;
		}
		cout << "Constructor. " << this << endl;
	};

	MyClass(const MyClass &other)
	{
		this->size = other.size;

		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Coping constructor. " <<this<< endl;

	}


	~MyClass()
	{
		cout << "Destructor. " << this << endl;
		delete[] data;
	};
private:
	int size;
};


void Foo(MyClass value)
{
	cout << "Foo" << endl;
}

MyClass Foo2()
{
	cout << "Foo2" << endl;
	MyClass temp(2);
	return temp;
}



int main()
{
	MyClass a(10);
	MyClass b(a);
	//Foo2();
	/*MyClass a(5);
	Foo(a);*/
}


