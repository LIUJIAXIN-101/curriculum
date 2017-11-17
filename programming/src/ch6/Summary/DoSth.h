#pragma once
#include <iostream>

/*
	������ʲô���Ļ���
*/
template<typename T>
class What2do
{
public:
	virtual void operator()(T &) = 0;
};

template<typename T>
class Show : public What2do<T> 
{
public:
	void operator()(T & obj)
	{
		std::cout << obj << std::endl;
	}
};

template<typename T>
class DoubleMe : public What2do<T>
{
public:
	void operator()(T & obj)
	{
		obj *= 2;
	}
};