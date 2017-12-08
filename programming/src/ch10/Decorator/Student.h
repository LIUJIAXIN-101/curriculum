#pragma once
#include <iostream>
#include <string>

/*
	�ӿ��ࣺѧ��
*/
class Student
{
public:
	virtual std::string getTitle() = 0;
	virtual int getStudyTime() = 0;
};

class Freshman : public Student
{
public:
	std::string getTitle()
	{
		return "��һѧ��";
	}
	int getStudyTime()
	{
		return 100;
	}
};

/*
	װ���ࣺѧ���ɲ�
*/
class StudentLeader : public Student
{
	Student & student;
public:
	Student & getStudent() { return student; }
	StudentLeader(Student & s) : student(s) {}
	std::string getTitle()
	{
		return student.getTitle();
	}
	int getStudyTime()
	{
		return student.getStudyTime();
	}
};


/*
	�೤
*/
class Monitor : public StudentLeader
{
public:
	Monitor(Student & s) : StudentLeader(s) {}

	std::string getTitle()
	{
		return "�೤ " + getStudent().getTitle();
	}
	int getStudyTime()
	{
		return getStudent().getStudyTime() - 5;
	}
};

/*
	��֧��
*/
class LeagueSecretary : public StudentLeader
{
public:
	LeagueSecretary(Student & s) : StudentLeader(s) {}

	std::string getTitle()
	{
		return "��֧�� " + getStudent().getTitle();;
	}
	int getStudyTime()
	{
		return getStudent().getStudyTime() - 2;
	}
};

class Commissary : public StudentLeader
{
public:
	Commissary(Student & s) : StudentLeader(s) {}

	std::string getTitle()
	{
		return "�༶ίԱ " + getStudent().getTitle();;
	}
	int getStudyTime()
	{
		return getStudent().getStudyTime() - 1;
	}
};
