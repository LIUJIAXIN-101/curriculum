#include <iostream>
#include <string>
#include <locale> 

/*
	unicode ���ֽ��ַ���ʹ��ʾ��
*/
void test_wchar()
{
	std::wcout.imbue(std::locale("chs"));
	std::cout << "size of wchar_t: " << sizeof(wchar_t) << std::endl;

	wchar_t wo = L'��';
	std::wcout << "wo: " << wo << std::endl;
//	wchar_t * p = L"�ҵ��й���";
	std::wstring str = L"�ҵ��й���";
	std::wcout << str << std::endl;
}

int main()
{
	test_wchar();
	system("pause");
    return 0;
}

