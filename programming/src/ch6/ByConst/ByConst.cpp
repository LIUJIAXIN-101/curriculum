#include "Potato.h"

void peel_potato_const(const Potato & p)
{
	//	p.peel();
}

void Potato::changeName(std::string n) const
{
//		name = n;
}

void test_const()
{
	Potato ob("Obama");

	peel_potato_const(ob);

	ob.changeName("Trump");
}

void test_assign()
{
	Potato a("Obama");
	Potato b("Trump");
	b = a;
//	Potato c = a;
}

void test_assign_agin()
{
	Potato a("Obama");
	Potato b("Trump");
	Potato x = (b = a);	// ����������
	Potato y = b = a;	// ����������
	x = b = a;			// �����⣬��Դ��ʲô��
}

int main()
{
//	test_assign();
	test_assign_agin();

	system("pause");
    return 0;
}

