//модификаторы доступа при наследовании


#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class A
{
public:

	string msgOne = "Message one";

private:

	string msgTwo = "Message two";

protected:

	string msgThree = "Message three";

};

class B : public A
{
public:
	void PrintMsg()
	{
		cout << msgThree << endl;
	}
};

int main()
{
	B b;
	b.PrintMsg();
}

