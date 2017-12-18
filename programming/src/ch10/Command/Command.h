#pragma once
#include <iostream>
#include <string>

/*
	�����receiver��ִ���ߣ�����Ա��
*/
class Programmer
{
public:
	void code()
	{
		std::cout << "start coding" << std::endl;
	}

	void install()
	{
		std::cout << "start installing" << std::endl;
	}

	void debug()
	{
		std::cout << "start debugging" << std::endl;
	}
};

/*
	����ӿ���
*/
class Command
{
public:
	virtual void execute() = 0;
};

/*
	����ʩ��� ����
*/
class Manager
{
public:
	void setCommand(Command *c) { command = c; }
	void act()
	{
		if (NULL == command)
		{
			std::cout << "no command" << std::endl;
			return;
		}
		command->execute();
	}
private:
	Command * command;
};

/*
	һ���ճ�����
*/
class RoutineCommand : public Command
{
public:
	RoutineCommand(Programmer * c) : coder(c) {}

	void execute()
	{
		coder->install();
		coder->code();
		coder->debug();
	}

private:
	Programmer * coder;
};

