#pragma once
#include <iostream>

/*
	��άƽ���ϡ��㡱�Ķ�����
*/
class Point
{
public:	

	Point(int x0, int y0) : x(x0), y(y0) {}		// (1)

	Point() { x = 0, y = 0; }					// (2)
//	Point() { Point(0, 0);						// ����(1),ʵ��(2)

	// �������캯��
	Point(const Point & other) : x(other.x), y(other.y) //const
	{
		std::cout<< *this <<" copy from "<<other<<std::endl;
	}

	// ���� <<��ʹcout֧�� Point���������
	friend std::ostream & operator<<(std::ostream &output, const Point &p);

	// ��ֵ������=
	Point operator = (const Point & other)
	{
		std::cout << *this << " <-- " << other << std::endl;
		x = other.x;
		this->y = other.y;							// this

		return *this;
	}

	// �ж��������Ƿ���ȣ���ͬ����ȣ���
	bool operator == (const Point & other)	const // const 
	{
		if (x != other.x)
			return false;

		if (y != other.y)
			return false;
	
		return true;
	}

private:
	int x, y;
};

std::ostream & operator<<(std::ostream &output, const Point &p) 
{
	return output << "("<<p.x << "," << p.y << ") at " << &p;
}

void test_point()
{
	Point a;
	Point b(0, 1);
	Point c(b);
	Point d = b;			// d �ող�����Ҫ����
	a = d;					// a �Ѿ�������ֱ�ӵ��� =

	std::cout <<" ====================== "<< std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}