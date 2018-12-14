//наследование


#include "pch.h"
#include <iostream>
using namespace std;

class Human
{
public:
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}
private:
	string name;
};



class Student : public Human
{
public:

	string group;
	void Learn()
	{
		cout << "I learn!" << endl;
	}
};

class ExtramuralStudent:public Student
{
public:
	void Learn()
	{
		cout << "I'm an extramural student!" << endl;
	}
};

class Professor:public Human
{
public:

	string subject;
};



int main()
{
	Human h;

	Student st;
	st.SetName("Fuck");
	cout << st.GetName() << endl;

	ExtramuralStudent extraSt;
	extraSt.SetName("Shit");
	cout << extraSt.GetName() << endl;

	extraSt.Learn();
	
	Professor pr;

}

