#pragma once

#include <iostream>
#include <string>

/*
	���糧�����ġ������硱
	�����ĵ�ѹ��ͬ��������仯
*/
class ACPowerSupplyer
{
public:
	ACPowerSupplyer(int v) : volt(v) {}

	int acoutput()	{return volt;}

private:
	int volt;
};
