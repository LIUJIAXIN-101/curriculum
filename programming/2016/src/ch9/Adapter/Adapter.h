#pragma once

#include "Power.h"

/*
	����ֱ���硱���豸
*/
class DCPowerSupplyer
{
public:
	virtual int dcoutput() = 0;
};

/*
	һ�������ֱ����ġ���������
*/
class Adapter : public DCPowerSupplyer
{
public:
	Adapter(const ACPowerSupplyer & as) : input(as){}

	int dcoutput()
	{
		if (input.acoutput() > 240 || input.acoutput() < 100)
			return input.acoutput() / 20;

		return 12;
	}

private:
	ACPowerSupplyer input;
};