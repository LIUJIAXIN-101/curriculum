#pragma once
#include <iostream>
#include <string>
#include "ColorSet.h"

class Weapon
{
public:
	virtual void attack() = 0;
	virtual std::string getName() = 0;
};

class Killer : public Weapon
{
public:
	Killer(std::string n) : name(n), weapon(NULL) {}

	std::string getName() { return name; }
	void equip(Weapon * e) 
	{
		weapon = e; 
		std::cout << name << "װ���� " << e->getName() << std::endl;;
	}

	void attack() 
	{ 
		std::cout << name << "\t";
		if (NULL == weapon)
		{
			std::cout<< "���ֿ�ȭ" << std::endl;
			return;
		}
	
		weapon->attack(); 
	}

private:
	std::string name;
	Weapon * weapon;
};

class Knife : public Weapon
{
	std::string getName() { return "�˵�"; }

	void attack()
	{
		std::cout << "���� ====/" << std::endl;
	}
};

class Gun : public Weapon
{
	std::string getName() { return "ǹ"; }

	void attack()
	{
		std::cout << "��ǹ ----->" << std::endl;
	}
};

class Bomb : public Weapon
{
	std::string getName() { return "ը��"; }
	void attack()
	{
		std::cout  << "�ۣ�" << std::endl;
	}
};

class AtomBomb : public Weapon
{
	std::string getName() { return "ԭ�ӵ�"; }
	void attack()
	{
		std::cout << "ATOM ATTACKING !!!!!!" << std::endl;
	}
};