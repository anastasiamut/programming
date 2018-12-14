// перегрузка оператора присвавания
//перешрузка оператора == и !=

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

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "Constructor. " << this << endl;
	};

	MyClass(const MyClass &other)// конструктор копирования
	{
		this->size = other.size;

		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Coping constructor. " << this << endl;

	}

	MyClass& operator = (const MyClass &other)// опер присваивания
	{
		cout << "Operator = " <<this<< endl;
		this->size = other.size;

		if (this->data != nullptr)
		{
			delete[] this->data;
		}

		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		return *this;
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

class Point
{
private:

	int x;
	int y;

public:
	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
	}

	Point(int valueX, bool boolean)
	{
		x = valueX;

		if (boolean)
		{
			y = 1;
		}
		else
		{
			y = -1;
		}
	}

	int GetX()
	{
		return x;
	}

	void SetX(int valueX)
	{
		x = valueX;
	}

	int GetY()
	{
		return y;
	}

	void SetY(int valueY)
	{
		y = valueY;
	}

	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl << endl;
	}
		

};

int main()
{
	MyClass  a(10);
	MyClass b(2);
	MyClass c(5);


	c=a = b;
	
}


