
#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926535897932;

double inputPrecision()
{
	double p;
	do
	{
		cin >> p;
		if (p <= 0)
		{
			cout << "It should be positive, try again ";
		}
		
	}
	while (p <= 0);
	return p;
}


double preciseCos(double angle, double precision)
{
	double previousSum = 0;
	double currentSum = 1;
	double term = -angle * angle / 2;//n+1й член
	const int firstValue = 4;
	for (int i(firstValue); abs(currentSum - previousSum) >= precision; i += 2)
	{
		previousSum = currentSum;
		currentSum += term;
		term *= -((angle * angle) / (i * (i - 1)));
	}
	return currentSum;
}

double Cos(double angle, double precision)
{
	double result;
	angle = fmod(angle, 2 * PI);// остаток от деления
	int sign = 1;

	if (PI / 2 < angle && angle < 3 * PI / 2)
	{
		// converting angle to one with positive cos
		sign = -sign;
		angle = abs(PI - angle);
	}

	if (PI / 4 < angle && angle < PI / 2) 
	{
		// then cos(x) = sqrt(1 - cos^2(PI / 2 - x))
		double cos = preciseCos(abs(PI / 2 - angle), precision);
		result = sqrt(1 - cos * cos);
	}
	else if (3 * PI / 2 < angle && angle < 7 * PI / 4)
	{
		double cos = preciseCos(abs(angle-3*PI/2),precision);
		result=sqrt(1-cos*cos);
	}
	else
	{
		result = preciseCos(angle, precision);
	}
	result *= sign;
	return result;
}

int main()
{
	double result;
	double angle;
	
	cout << "Input precision: ";
	double precision = inputPrecision();

	cout << "Input angle: ";
	cin >> angle;
	cout << "Cos(" << angle << ") = " << Cos(angle, precision) << endl;
	cout << "Checking with cmath: cos = " << cos(angle) << endl;
}
