//что такое класс. что такое объект класса. методы класса. функции класса


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
		cout << "Name: " << name << "\tWeight: " << weight << "\tAge: " << age << endl<<endl;
	}

};

class Point
{
public:

	int x;
	int y;
	int z;
};

int main()
{
	Human firstHuman;
	firstHuman.age = 19;
	firstHuman.name = "Nastya";
	firstHuman.weight = 57;

	firstHuman.Print();

	Human secondHuman;
	secondHuman.name = "Noname";
	secondHuman.age = 22;
	secondHuman.weight = 100;

	secondHuman.Print();

	//Point a;
	//a.x = 1;
	//a.y = 3;
	//a.z = 5;







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
