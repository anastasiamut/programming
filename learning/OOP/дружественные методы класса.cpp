//дружественные методы класса


#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


class Apple;
class Human;


class Human
{
public:
	void TakeApple(Apple &apple);
	void EatApple(Apple &apple)
	{

	}
};



class Apple
{
public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
private:
	int weight;
	string color;

	friend void Human::TakeApple(Apple &apple);
};



int main()
{

	Apple apple(150, "Red");
	Human human;
	human.TakeApple(apple);

}

void Human::TakeApple(Apple & apple)
{
	cout << "TakeApple " << "weight = " << apple.weight << " Clolor = " << apple.color;
}
