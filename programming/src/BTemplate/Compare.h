#pragma once
#include<iostream>
#include<cmath>

// ����
template <class T>
class Compare
{
public:
	bool equal(T& a,  T& b)
	{
		std::cout << "generic compare" << std::endl;
		return (a == b);
	}
};

// �ػ�Ϊfloat
template <>
class Compare<float>
{
public:
	bool equal( float& a, float& b)
	{
		std::cout << "float compare" << std::endl;
		return (abs(a - b) < 10e-3);
	}
};

// �ػ�Ϊdouble
template <>
class Compare<double>
{
public:
	bool equal(double& a, double& b)
	{
		std::cout << "doble compare"<< std::endl;
		return (abs(a - b) < 10e-6);
	}
};