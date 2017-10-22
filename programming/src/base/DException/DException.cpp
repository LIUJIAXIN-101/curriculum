#include <iostream>

void test_divide()
{
	// û�����쳣����� ��������
	try
	{
		float m = 0;
		double res = 5.1 / m;
		std::cout << res << std::endl;
	}
	catch (...)
	{
		std::cout << "some exception" << std::endl;
	}
}

double exception_divide(int a, int b)
{
	if (b == 0)
	{
		throw "Exception: divisor is 0";
	}

	return double(a / b);
}

void test_exception_divide()
{
	// ��0���
	try
	{
		double res = exception_divide(51, 0);
		std::cout << "result is:\t" << res << std::endl;
	}
	catch (const char * exception)
	{
		std::cout << "result is:\t" << exception << std::endl;
	}
}
/*
	���׳��쳣����ʾ�쳣���
*/
int accumulate(int arr[], int size)
{
	int result = 0;
	for (int i =0; i<size; i++ )
	{
		if (arr[i] > 100 || arr[i] < -100)
		{
			throw 0;
		}
		if (arr[i] < 0)
		{
			throw "negtive";
		}
		result += arr[i];
	}

	return result;
}

void test_accumulate()
{
	// ���ص���Сֵ����
	int arr[5] = { -13, 7, 13, 13, 27 };
	// ���쳣������ȷ��
	try
	{
		int sum = accumulate(arr, 5);
		std::cout << "sum is:\t" << sum << std::endl;
	}
	catch (int e)
	{
		if (e == 0)
			std::cout << "some value is exceptional" << std::endl;
	}
}
void test_inf()
{
	double a = 10;
	double b = a / 0.0;
	std::cout << b << std::endl;
}

void test_epsilon()
{
	double a = 10;
	double b = a / 0.0000000000000000000000000000000000000000000000000000000000000000000000001;
	std::cout << b << std::endl;
}

int main()
{
	// test_epsilon();
	// test_inf();
	// test_divide();
	// test_exception_divide();
	 test_accumulate();



	system("pause");
	return 0;
}

