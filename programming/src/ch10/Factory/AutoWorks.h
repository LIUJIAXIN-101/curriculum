#pragma once
#include <iostream>


class AutoMobile
{
public:
	virtual void run() = 0;
};

// ��ʿ
class Bus : public AutoMobile {};

// �γ�
class MotorCar : public AutoMobile{};

// Benz �γ�
class BenzCar : public MotorCar
{
	BenzCar() {}

public :
		friend class BenzWorks;
	void run()
	{
		std::cout <<"Benz Car start ------>"<< std::endl;
	}
};

// ���۴��
class BenzBus : public Bus
{
	BenzBus() {}
	friend class BenzWorks;
public:
	void run()
	{
		std::cout << "Benz Bus start ------>" << std::endl;
	}
};

// ����γ�
class ToyotaCar : public MotorCar
{
	ToyotaCar() {}
	friend class ToyotaWorks;
public:
	void run()
	{
		std::cout << "Toyota Car start ------>" << std::endl;
	}
};

// ������
class ToyotaBus : public Bus
{
	ToyotaBus() {}
	friend class ToyotaWorks;
public:
	void run()
	{
		std::cout << "Toyota Bus start ------>" << std::endl;
	}
};

/*
	���󹤳�ʵ��
	������������
*/
class AutoWorks
{
public:
	virtual Bus * produceBus() = 0;
	virtual MotorCar * produceCar() = 0;
};

// ����������
class BenzWorks : public AutoWorks
{
public:
	Bus * produceBus()
	{
		return new BenzBus();
	}
	MotorCar * produceCar()
	{
		return new BenzCar();
	}
};

// ����������
class ToyotaWorks : public AutoWorks
{
public:
	Bus * produceBus()
	{
		return new ToyotaBus();
	}
	MotorCar * produceCar()
	{
		return new ToyotaCar();
	}
};