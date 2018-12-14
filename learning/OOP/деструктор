//


//конструктор класса. перегрузка конструктора классов


#include "pch.h"
#include <iostream>
using namespace std;



class MyClass
{
private:
	int* data;
public:

	MyClass(int size)
	{
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}

		cout << "Object "<<data<<" Constructor. " << endl;
	}

	~MyClass()
	{
		delete[] data;
		cout <<"Object "<<data<< " Destructor. " << endl;
	}

};

void Foo()
{
	cout << "Foo begins" << endl;
	MyClass a(1);
	cout << "Foo ends" << endl;
}

int main()
{
	Foo();

}





