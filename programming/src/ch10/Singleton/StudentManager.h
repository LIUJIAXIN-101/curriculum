#pragma once
#include <iostream>
#include <string>
#include <map>

class StudentManager
{
	StudentManager() {}						// ˽�л���
public:
	static StudentManager * getInstance()
	{
		return instance;
	}

	static void destroy()
	{
		if (instance != NULL)
		{
			delete instance;
			instance = NULL;
		}
	}

	void init();

	std::string findNameByID(int i);

	int findScoreByID(int i);

	// ���ʣ� a �� b ��ʲô����
	void modifyScore(int, int);			// a

	void setScore(int, int);			// b

private:
	static StudentManager * instance;

	std::map<int, std::string> idName;

	std::map<int, int>idScore;
};