#include <iostream>

// ��ֵ
void show_value(int a)
{
	std::cout << "func:\t" << a << "\taddress:\t" << &a << std::endl;
}

// ������
void show_ref(int & a)
{
	std::cout << "func:\t" << a << "\taddress:\t" << &a << std::endl;
}

void swap_value(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}
void swap_pointer(int * a, int * b)
{
	int * c = a;
	a = b;
	b = c;
}

void swap(int & a, int & b)
{
	int c = a;
	a = b;
	b = c;
}

int main()
{

	int value = 127; int * p_value = &value;

	int & ref = value; int * p_ref = &ref;

	int temp = value; int * p_temp = &temp;

	std::cout << "value:\t" << value << "\taddress:\t" << p_value << std::endl;

	std::cout << "ref:\t" << ref << "\taddress:\t" << p_ref << std::endl;

	std::cout << "temp:\t" << temp << "\taddress:\t" << p_temp << std::endl;

	show_value(value);  // show_value(127); ��ֵ

	show_ref(value);   // show_value(value) ����ȥһ������


	system("pause");
	return 0;
}

