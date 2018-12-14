//конструктор класса. перегрузка конструктора классов


#include "pch.h"
#include <iostream>
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
	



	Point a;
	a.Print();

	Point b(5, 14);
	b.Print();

	Point c(22, false);
	c.Print();


	//a.SetX(5);
	//a.SetY(11);



	////int result = a.GetX();
	////cout << result << endl;

}



