#pragma once
#include <iostream>
#include <string>

/*
	�򵥹��� ģʽ��ʾ��
	����֮��
*/
class Object
{
public:
	virtual void show() = 0;
};

class Movable
{
public:
	virtual void move() = 0;
};

class Animal : public Object, public Movable
{
	
};

/*
	��˵Ҫ�й⣬���Ǿ����˹�
*/
class Light :public Object
{
	friend class God;
	Light() {}
public:
	void show()
	{
		std::cout << "So there is light" << std::endl;
	}
};

/*
	һ�ֶ���
*/
class Human : public Animal
{
	friend class God;
	Human(){}
public:
	void show() 
	{
		std::cout << "I am a man!" << std::endl;
	}
	void move()
	{
		std::cout << "Human moving" << std::endl;
	}
};

/*
	��һ�ֶ���
*/
class Baboon : public Animal
{
	friend class God;
	Baboon() {}
public:
	void show()
	{
		std::cout << "Baboon!" << std::endl;
	}
	void move()
	{
		std::cout << "Baboon moving" << std::endl;
	}
};


/*
	���ܵ��ϵۣ�ʲô��������
	һ��ͬ�ʣ�һ�н�Ϊ ���
*/
class God
{
public:
	static Object * produce(std::string what)
	{
		if (what == "human")
			return new Human();
		else if (what == "light")
			return new Light();
		else if (what == "baboon")
			return new Baboon();
	
		return NULL;
	}
};