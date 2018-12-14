//Static

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
		count++;
		id = count;
	}

	int GetId()
	{
		return id;
	}

	static int GetCount()
	{
		return count;
	}

	static void ChangeColor(Apple &apple, string color)
	{
		apple.color = color;
	}

private:
	static int count;
	int weight;
	string color;
	int id;

};

int Apple::count = 0;


int main()
{

	Apple apple(150, "Red");

	Apple::ChangeColor(apple, "Green");


	//Apple apple2(10, "Green");
	//Apple apple3(200, "Yellow");

	//cout << apple.GetId() << endl;
	//cout << apple2.GetId() << endl;
	//cout << apple3.GetId() << endl;

	//cout<<Apple::GetCount() << endl;
	//cout << apple3.GetCount() << endl;


	/*cout << apple.count << endl;
	cout << apple2.count << endl;
	cout << apple3.count << endl;*/

	//cout << Apple::count << endl;
}

void Human::TakeApple(Apple & apple)
{
	//apple.color = "";
	cout << "TakeApple " << "weight = " << apple.weight << " Clolor = " << apple.color;

}



