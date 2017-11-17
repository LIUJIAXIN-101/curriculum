#pragma once
#include <string>
#include <iostream>

/*
	һ��������ѧ��������
	ѧ������ 3 �� ����
	ID : ѧ��
	name : ����
	score : ѧ��
*/
class Student
{
	typedef unsigned int uint;
	typedef unsigned short ushort;

public:
	Student() : id(0), name(""), score(0) {}
	Student(uint i, std::string n) : id(i), name(n), score(0) {}
	Student(uint i, std::string n, ushort s) : id(i), name(n),score(s) {}

	void setScore(int s) { score = s; }

	inline void operator *= (int i){score *= i;}

	Student & operator = (const Student & other)
	{
		id = other.id; name = other.name; score = other.score;
		return *this;
	}

	Student (const Student & other)
	{
		id = other.id; name = other.name; score = other.score;
		std::cout << "construct :" <<(*this)<<"\at"<<std::endl;
	}

	void loadFromString(std::string);

	friend std::ostream & operator << (std::ostream & output, const Student & s);
private:
	uint id;			// ѧ��
	std::string name;	// ����
	ushort score;		// ����
};

