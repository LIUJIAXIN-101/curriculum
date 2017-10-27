#pragma once
#include <iostream>

int getSize(char para[100]) // char para[], char * para
{
	return sizeof(para);
}

void test_size()
{
	char name[15] = "huang";
	std::cout <<"name[15] size is:\t"<< sizeof(name)<< std::endl;

	char title[] = "President";
	std::cout << "title[] size is:\t" << sizeof(title) << std::endl;

	char location[] = "Harbin";
	std::cout << "getSize is:\t" << getSize(location) << std::endl;

	char * p = "abcdefg";
	std::cout << "p size is:\t" << sizeof(p) << std::endl;

}

void test_location()
{
	char * p = "abcdefg";
	char * q = "abcdefg";
	const char * r = "abcdefg";
	char name[] = "abcdefg";

	std::cout << "p:\t" << p << "\tloc:\t" << (int *)p << std::endl;
	std::cout << "q:\t" << q << "\tloc:\t" << (int *)q << std::endl;
	std::cout << "r:\t" << r << "\tloc:\t" << (int *)r << std::endl;
	std::cout << "name:\t" << r << "\tloc:\t" << (int *)name << std::endl;

}

void test_const()
{
	char name[] = "abcdefg";
	char * p = "abcdefg";
	const char * q = "abcdefg";

//	p[3] = 't';			// ���������Σ��
//	q[3] = 't';			// �����޷���ֵ
	std::cout << "p : " << p << std::endl;
	std::cout << "q[3] : " << q[3] << std::endl;

	p = name;
	p[3] = 't';
	std::cout << "p : " << p << std::endl;

	q = name;
//	q[3] = 't';			// ���ǲ���
	std::cout << "p : " << p << std::endl;
}

void test_const_where()
{
	const char * a = "Barbin";
	char * const p = "Beijing";
	const char * const q = "Hangzhou";
//	p = q;						// ���벻�� 
//	q = a;						// ���벻��
}