#include<iostream>

/*
	��ֱ���Debug/Release�½��в���
	������в��죬�����ǵ��Է��Ŵ�����
*/
void show_int()
{
	std::cout << "----INT-----" <<std::endl;
	int a = 13, b = 25;

	int *pa = &a, *pb = &b;
	int pva = (int)pa;
	int pvb = (int)pb;

	std::cout << pa << "\t" << pb << "\t" <<(pb-pa) <<std::endl;
	std::cout << pva << "\t" << pvb << "\t" << (pvb - pva) << std::endl;
}

void show_char()
{
	std::cout << "----CHAR-----" << std::endl;
	char a = 'a', b = 'b';

	char *pa = &a, *pb = &b;
	int pva = (int)pa;
	int pvb = (int)pb;

	std::cout << (void*)pa << "\t" << (void*)pb << "\t" << (pb - pa) << std::endl;
	std::cout << pva << "\t" << pvb << "\t" << (pvb - pva) << std::endl;
}

struct Pair
{
	int a;
	int b;

	void show()
	{
		std::cout << "----PAIR-----" << std::endl;
		int *pa = &a, *pb = &b;
		int pva = (int)pa;
		int pvb = (int)pb;

		std::cout << pa << "\t" << pb << "\t" << (pb - pa) << std::endl;
		std::cout << pva << "\t" << pvb << "\t" << (pvb - pva) << std::endl;

	}

};

int main()
{
	show_int();
	show_char();

	Pair pair;
	pair.a = 10; pair.b = 23;

	pair.show();


	system("pause");
    return 0;
}

