#include <iostream>
void test_read()
{
	// ����·��
	//E:\doc\�γ�\repos\programming\src\ch5\File\File\File.cpp 
	const char * file_name = "E:\\doc\\�γ�\\repos\\programming\\src\\ch5\\File\\File\\File.cpp";
	//const char * file_name = "test.txt";  //  ���·��
	//const char * file_name = "File.cpp";  //  ���·��

	FILE * fp;
	fopen_s(&fp, file_name, "r");
	if (!fp)
	{
		std::cout << "cannot find the file" << std::endl;
		return;
	}

	char buff[1000];
	memset(buff, 0, 1000);
	fread(buff, 1, 999, fp);
	std::cout << buff << std::endl;
	fclose(fp);
}

void test_write()
{
	const char * file_name = "out.txt";  //  ���·��										

	FILE * fp;
	fopen_s(&fp, file_name, "w");
	if (!fp)
		return;

	char str[] = "������������������������˵ֻ��һ�Ρ�\
�˵�һ��Ӧ�������ȹ���������������ʱ��������Ϊµµ��Ϊ��\n\
����껪���ںޣ�Ҳ������ΪΪ�˱��ӣ�����ӹ�׶�����";	
	fwrite(str, 1, strlen(str)+1, fp);
//	std::cout << buff << std::endl;
	fclose(fp);						// ע�͵�������������
}


void test_get()
{
	const char * file_name = "test.txt";  //  ���·��

	FILE * fp;
	fopen_s(&fp, file_name, "r");
	if (!fp)
		return;

	char c = fgetc(fp);
	std::cout << c << std::endl;
	fseek(fp, 20, SEEK_CUR); // #define SEEK_CUR    1
							 // #define SEEK_END    2
							 // #define SEEK_SET    0
	c = fgetc(fp);
	std::cout << c << std::endl;
	c = fgetc(fp);
	std::cout << c << std::endl;

	fclose(fp);
}
int main()
{
	//test_read();
	//test_write();
	test_get();
	system("pause");
    return 0;
}

