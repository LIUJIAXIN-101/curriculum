#include<iostream>

// argc ��������������argv�а������ַ�������Ŀ
// argv ��һ���ַ�������
// argv[0],���ǳ�������ļ���
int main(int argc, char * argv[])
{
	printf("Hello world\n");

	std::cout << "OK, C ++ " << std::endl;
	using namespace std;
	cout << "OK, using namespace" << endl;

	cout << argc << endl;

	for (int i = 0; i < argc; i++)
		cout << argv[i] << endl;

	system("pause");
	return 0;
}