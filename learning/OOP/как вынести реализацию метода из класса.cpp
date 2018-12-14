//как вынести реализацию метода из класса


#include "pch.h"
#include <iostream>
using namespace std;

class MyClass
{
public:

	void PrintMessage();


};


void MyClass::PrintMessage()
{
	
	cout << "Hello!" << endl;
	
}

int main()
{
	MyClass a;
	a.PrintMessage();
}

