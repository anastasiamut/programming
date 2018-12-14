//Абстрактный класс


#include "pch.h"
#include <iostream>
using namespace std;

class Weapon//абстрактный класс
{
public:
	virtual void Shoot() = 0;
	void Foo()
	{
		cout << "Foo()" << endl;
	}
};


class Gun:public Weapon
{
public:
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};


class SubmachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "Bang! Bang! Bang!" << endl;
	}
};

class Bazooka :public Weapon
{
public:
	void Shoot()override
	{
		cout << "KABOOM!!!" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon *weapon)
	{
		weapon->Shoot();
	}
};

class Knife :public Weapon
{
public:
	void Shoot()override
	{
		cout << "VJUHH!!" << endl;
	}
};


int main()
{
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazooka;
	Knife knife;
	

	Weapon* weapon = &machinegun;
	Weapon* weapon1 = &gun;
	Weapon* weapon2 = &bazooka;
	Weapon* weapon3 = &knife;




	//weapon->Shoot();
	//weapon1->Shoot(); //это полиморфизм 

	Player player;

	player.Shoot(&gun);
	player.Shoot(&machinegun);
	player.Shoot(&bazooka);
	player.Shoot(&knife);
}

