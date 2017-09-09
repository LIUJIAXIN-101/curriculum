#include <iostream>

double DividedBy(int a, int b)
{
	if (b == 0)
	{
		throw "Exception: divisor is 0";
	}

	return double(a / b);
}

int getMin(int arr[], int size)
{
	int min = 0x7fffffff;
	for (int i = 0; i < size; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

int getMin_E(int arr[], int size)
{
	if (size == 0)
		throw 0;

	int min = 0x7fffffff;
	for (int i = 0; i < size; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

int main()
{
	// ��0���
	try
	{
		double res = DividedBy(51, 0);
		std::cout << "result is:\t" << res << std::endl;
	}
	catch (const char * exception)
	{
		std::cout << "result is:\t" << exception << std::endl;
	}

	// û�����쳣����� ��������
	try
	{
		float m = 0;
		double res = 5.1 / m;
	}
	catch (...)
	{
		std::cout << "some exception" << std::endl;
	}

	// ���ص���Сֵ����
	int arr[1];
	int min = getMin(arr, 0);
	std::cout << "min is:\t" << min <<"("<< std::hex<< min<<")"<<std::endl;

	// ���쳣������ȷ��
	try
	{
		int min = getMin_E(arr, 0);
		std::cout << "min is:\t" << min << "(" << std::hex << min << ")" << std::endl;
	}
	catch (int e)
	{
		if(e == 0)
			std::cout << "array is empty" << std::endl;
	}

	system("pause");
	return 0;
}

