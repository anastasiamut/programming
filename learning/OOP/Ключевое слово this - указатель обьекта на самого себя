//Ключевое слово this - указатель обьекта на самого себя


#include "pch.h"
#include <iostream>
using namespace std;

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
		cout << this << " Constructor." << endl;
	}
	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
		cout << this << " Constructor." << endl;
	}

	void Print()
	{
		cout << "X= " << x << "\tY= " << y << endl;
	}

	void SetY(int y)
	{
		this->y = y;
	}

};



int main()
{
	Point a;
	a.SetY(5);
	a.Print();


	
}

