#include<iostream>
using namespace std;
// argc ��������������argv�а������ַ�������Ŀ
// argv ��һ���ַ�������
// argv[0],���ǳ�������ļ���
int main(int argc, char * argv[])
{
	cout << "OK, using namespace" << endl;

	cout << argc << endl;
	if (argc < 2)
	{
		cout << "not enough!" << endl;
		return 0;
	}	

	for (int i = 0; i < argc; i++)
		cout << argv[i] << endl;

	int result =  atoi(argv[1]) + atoi(argv[2]);

	cout << "result is :" <<result<< endl;



	system("pause");
	return 0;
}