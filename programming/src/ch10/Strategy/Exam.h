#pragma once
#include <iostream>
#include <string>

class PassExamStrategy
{
public:
	virtual void takeExam() = 0;
};

class Student
{
	PassExamStrategy * how2do;

public:
	void useStrategy(PassExamStrategy * strategy)
	{
		how2do = strategy;
	}

	void pass()
	{
		std::cout << "����ʹ��";
		how2do->takeExam();
		std::cout << "ͨ������" << std::endl;
	}
};

class ReviewHardly : public PassExamStrategy
{
public:
	void takeExam()
	{
		std::cout << "Ŭ�����Ը�ϰ�Ĳ���";
	}
};

class Cheat : public PassExamStrategy
{
public:
	void takeExam()
	{
		std::cout << "���׵Ĳ���";
	}
};

class FakeExam : public PassExamStrategy
{
public:
	void takeExam()
	{
		std::cout << "�濼�Ĳ���" ;
	}
};

