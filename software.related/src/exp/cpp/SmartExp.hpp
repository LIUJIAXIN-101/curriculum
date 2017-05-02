#pragma once
#include <string>
/*
	�����������ͺ��� ���� ֱ��������ʽ
	����ֵ�� Ҫô�ǽ����Ҫô�Ǳ�����Ϣ
*/
std::string smartExpCalc(std::string exp);

/*
	һ�����ʽ��ֵ��
*/
class SmartExp
{
public:

	SmartExp(std::string s) : exp(s), errInfo("") {}
	
	//	�������������������� getErrorInfo�鿴
	
	double calculate();

	std::string  getErrorInfo() { return errInfo; }

private:

	std::string exp;
	std::string errInfo;
};
