#include "Everyone.h"
#include "EveryoneTemplate.h"

void test()
{
	int arr[10];
	// init
	for (int i = 0; i < 10; i++)
		arr[i] = i * 2;
	// end init

	ShowMe showme;	// showme ��ShowMe���һ������
	Clear clr;

	for_everyone(arr, 10, showme);		// (1)
	for_everyone(arr, 8, clr);			// (2)
	for_everyone(arr, 10, ShowMe());	// (3) �� (1)��ʲô���

	// ShowMe()��һ����ʱ����
}

void test_template()
{
	float arr[10];
	// init
	for (int i = 0; i < 10; i++)
		arr[i] = i + 0.7f;
	// end init

	for_everyone_t(arr, 10, Show<float>());
	for_everyone_t(arr, 5, DoubleMe<float>());
	for_everyone_t(arr, 10, Show<float>());
}

int main()
{
	test();
	test_template();
	system("pause");
    return 0;
}

