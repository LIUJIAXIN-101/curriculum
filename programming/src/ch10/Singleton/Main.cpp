#include "God.h"
#include "StudentManager.h"

God God::instance;  // ȫ�ֹ���,�����������Ƕ�����

void testGod()
{
	God::getInstance().show();

	for (int i = 1;i <=7; i++)
	{
		std::string task = God::getInstance().what2do(i);
		std::cout << "��" << i << "�죺" << task << std::endl;
	};
}

void testManager()
{
	StudentManager::getInstance()->init();
	int a = 10063, b = 11243;
	std::string aname = StudentManager::getInstance()->findNameByID(a);
	std::string bname = StudentManager::getInstance()->findNameByID(b);

	std::cout << a << "," << aname << std::endl;
	std::cout << b << "," << bname << std::endl;

	StudentManager::getInstance()->destroy();
}

int main()
{
	//testGod();
	testManager();

	system("pause");
    return 0;
}

