// MonteCarlo

#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

double function(double x, double y)
{
	return x * x + y * y;
}

int inputPrecision()
{
	int n;
	cout << "Enter n (Precision) (N>0): \n";
	do
	{
		cin >> n;
		if (n <= 0)
			cout << "Enter positive number: \n";
	} while (n <= 0);

	return n;
}




double sumCalculation(double upX,double lowX, double lowY,double upY, int n)
{
	double sum = 0;
	double x, y;
	srand(time(NULL)); //Генерирует случайное число, используя текущею дату, как параметр, как бы для непредсказуемости результата
	for (int i = 0; i < n; i++)
	{
		x = lowX + (upX - lowX)*(double(rand()) / RAND_MAX);// [0;1]
		y = lowY + (upY - lowY)*(double(rand()) / RAND_MAX);

		double checkUpY = 2 * x - 1; 
		if ((y > lowY) && (y < checkUpY)) // проверка не вылазит ли У за 2х-1
			sum += function(x, y);
	}
	return sum;
}



int main()
{
	int n = inputPrecision();
	double upX = 1;
	double upY = 2 * upX - 1;
	double lowX = 0.5;
	double lowY = 0;
	double sum = sumCalculation(upX, lowX, lowY, upX, n);
	
	cout << "The Integral is: " << sum * (upX - lowX)*(upY - lowY) / n;
}
