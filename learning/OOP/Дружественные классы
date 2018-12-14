//Дружественные классы


#include "pch.h"
#include <iostream>
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
	friend Human;// это нарушает инкапсуляцию

public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
private:
	int weight;
	string color;

};



int main()
{

	Apple apple(150, "Red");
	Human human;
	human.TakeApple(apple);

}

void Human::TakeApple(Apple & apple)
{
	//apple.color = "";
	cout << "TakeApple " << "weight = " << apple.weight << " Clolor = " << apple.color;
	
}


