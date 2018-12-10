#pragma once
#include <string>
#include <iostream>
#include "ColorSet.h"

class Soldier
{
public:
	Soldier(std::string n) : name(n) {}

	std::string getName() { return name; }

	void attack()
	{
		setWhite();
		std::cout << "ͽ��ʿ��" <<getName() << "\t" <<  "ȭ�����" << std::endl;
	}

private:
	std::string name;
};

class KnifeSoldier : public Soldier
{
public:
	KnifeSoldier(std::string n) : Soldier(n) {}

	void attack()
	{
		setRed();
		std::cout << "��������" << getName() << "\t" << "���� ====/" << std::endl;
	}
};

class GunSoldier : public Soldier
{
public:
	GunSoldier(std::string n) : Soldier(n) {}

	void attack()
	{
		setMagenta();
		std::cout << "ǹ��" << getName() << "\t" << "��ǹ ----->" << std::endl;
	}
};

class Sniper : public Soldier
{
public:
	Sniper(std::string n) : Soldier(n) {}

	void attack()
	{
		setGreen();
		std::cout << "�ѻ���" << getName() << " �ѻ� ===> " << std::endl;
	}
};