// Геттеры и сеттеры. инкапсуляция

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class Human
{
public:
	string name;
	int age;
	int weight;
};

class Point
{
public:

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
		y = valueY*2;
	}
	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl << endl;
	}

private:

	int x;
	int y;


};


class CoffeeGrinder
{
private:

	bool CheckVoltage()
	{
		return true;
	}

public:

	void Start()
	{

		if (CheckVoltage())
		{
			cout << "VjuHHH!!" << endl;
		}
		else
		{
			cout << "Beep Beep" << endl;
		}
		
	}
};



int main()
{
	CoffeeGrinder a;
	a.Start();




	//Point a;

	//a.SetX(5);
	//a.SetY(11);

	//a.Print();

	////int result = a.GetX();
	////cout << result << endl;

}

