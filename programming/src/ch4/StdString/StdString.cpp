#include <iostream>
#include <string>

void test_string()
{
	std::string a = "my ";
	std::string b("chinese");
	std::string c = a + b + " name";	

	std::cout << c << std::endl;
	std::cout << "string c length is:\t" << c.length() << std::endl;
	std::cout << "string c size is:\t" << c.size() << std::endl;

	std::string me = "��";
	std::cout << me << std::endl;
	std::cout << me.size() << std::endl;
	std::cout << me.length() << std::endl;

	const char * str = c.c_str();
	std::cout << "const char * str:\t" << str << std::endl;
	const char ch = c.at(3);
	std::cout << "c.at(3):\t" << ch <<std::endl;
}

void test_use()
{
	using namespace std;

	string str = "my chinese name";

	string sub = str.substr(4, 8); //(��ʼλ�ã��ƶ���Զ)

	std::cout << "sub is:\t" << sub << std::endl;

	size_t pos = str.find(" ");
	std::cout << "find:\t" << pos << std::endl;
	pos = str.find_last_of(" ");
	std::cout << "find last:\t" << pos << std::endl;
}

/*
	һ���ۺϵ�СӦ�ã�����ַ�����ָ�����ַ�
	ΪʲôҪ�����ã�
*/
void trim(std::string & s, std::string sep)
{
	if (s.empty())
		return;

	size_t pos = s.find_first_of(sep);
	while (pos != std::string::npos)
	{
		s.erase(pos, 1);
		pos = s.find_first_of(sep);
	}
}

void test_trim()
{
	std::string str = "my chinese name is Huang xx";
	trim(str, " ");
	std::cout << str << std::endl;

	str = "Brazil,Russia,India,China,South Africa";
	trim(str, ",");
	std::cout << str << std::endl;

}

int main()
{
//	test_string();
//	test_use();
	test_trim();
	system("pause");
    return 0;
}

