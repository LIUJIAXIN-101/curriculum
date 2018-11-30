#pragma once
#include <iostream>

// ������ࡰ����ʲô��
class DoSth
{
public:
	virtual void operator()(int &) = 0;
};

// ������ʾ��
class ShowMe : public DoSth
{
public:
	void operator()(int & obj)
	{
		std::cout << obj << std::endl;
	}
};

// �� ����ֵ��
class Clear : public DoSth
{
public:
	void operator()(int & obj)		// ΪʲôҪ��& ?
	{
		obj = 0;
	}
};

/*
	��ÿ��Ԫ�أ���XX����
	XX ���� �� DoSth ������
*/
void for_everyone(int arr[], int size, DoSth & op)
{
	for (int i = 0; i < size; i++)
	{
		op(arr[i]);
	}
}
