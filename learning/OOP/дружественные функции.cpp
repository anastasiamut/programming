//дружественные функции


#include "pch.h"
#include <iostream>
using namespace std;


class Test;

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

	//int GetX()
	//{
	//	return x;
	//}

	void SetX(int valueX)
	{
		x = valueX;
	}

	int GetY()
	{
		return y;
	}

	//void SetY(int valueY)
	//{
	//	y = valueY;
	//}

	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl << endl;
	}
	friend void ChangeX(Point &value, Test &tvalue);
};

class Test
{
private:
	int data = 0;

	friend void ChangeX(Point &value, Test &tvalue);
};


void ChangeX(Point &value, Test &tvalue)
{
	value.x= -1;
	tvalue.data = -1;
}

int main()
{
	Point a(5, 12);
	Test test;

	a.Print();

	ChangeX(a, test);

	a.Print();
}

