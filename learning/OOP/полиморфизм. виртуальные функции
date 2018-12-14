//полиморфизм. виртуальные функции


#include "pch.h"
#include <iostream>
using namespace std;



class Gun
{
public:
	virtual void Shoot()
	{
		cout << "BANG!" << endl;
	}
};


class SubmachineGun: public Gun
{
public:
	void Shoot() override
	{
		cout << "Bang! Bang! Bang!" << endl;
	}
};

class Bazooka :public Gun
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
	void Shoot(Gun *gun)
	{
		gun->Shoot();
	}
};


int main()
{
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazooka;

	Gun* weapon = &machinegun;
	Gun* weapon1 = &gun;
	Gun* weapon2 = &bazooka;



	//weapon->Shoot();
	//weapon1->Shoot(); //это полиморфизм 

	Player player;

	player.Shoot(&gun);
	player.Shoot(&machinegun);
	player.Shoot(&bazooka);
}

