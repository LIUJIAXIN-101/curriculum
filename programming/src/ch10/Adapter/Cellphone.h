#pragma once
#include"Adapter.h"

/*
	���ڲ��Եġ��ֻ��ࡱ
	ֻ���� 5V �ġ�ֱ���硱���г��
*/
class Cellphone
{
public:
	void charge(DCPowerSupplyer & ds)
	{
		if (ds.dcoutput() > 5)
		{
			std::cout << "boom" << std::endl;
			return;
		}
		if (ds.dcoutput() < 5)
		{
			std::cout << "��ѹ̫�ͣ�ֻ��" << ds.dcoutput() << "��" << std::endl;
			return;
		}
		std::cout << "�����======================" << std::endl;
	}
};