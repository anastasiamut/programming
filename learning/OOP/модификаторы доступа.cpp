//модификаторы доступа


#include "pch.h"

#include <iostream>
#include <string>
using namespace std;


class Human
{
public:

	int age;   // svoistva, polya
	int weight;
	string name;

	void Print()
	{
		cout << "Name: " << name << "\tWeight: " << weight << "\tAge: " << age << endl << endl;
	}

};

class Point
{

public:
	int x;

//protected: //при наследовании будет доступно
	void Print()// это метод класса
	{
		cout << "y = " << y << "\tz = " << endl;
		PrintY();
	}
private: 
	int y;
	int z;
	void PrintY()
	{
		cout << "PrintY()" << endl;
		cout << y << endl;
	}
};

int main()
{
	Point a;
	a.Print();

	//Human firstHuman;
	//firstHuman.age = 19;
	//firstHuman.name = "Nastya";
	//firstHuman.weight = 57;

	//firstHuman.Print();

	//Human secondHuman;
	//secondHuman.name = "Noname";
	//secondHuman.age = 22;
	//secondHuman.weight = 100;

	//secondHuman.Print();








	/*cout << firstHuman.age << endl;
	cout << firstHuman.name << endl;
	cout << firstHuman.weight << endl;
	cout << "*********************" << endl;

	Human secondHuman;
	secondHuman.age = 19;
	secondHuman.name = "Noname";
	secondHuman.weight = 60;
	cout << secondHuman.age << endl;
	cout << secondHuman.name << endl;
	cout << secondHuman.weight << endl;
	cout << "*********************" << endl;*/
}
