#include "DataFile.h"

void DataFile::load(Array<Student> & arr)
{
	std::ifstream in(fileName);

	if (!in.is_open())
	{
		std::cout << "cannot open the file" << std::endl;
		return;
	}

	char buffer[100];
	int count = 0;
	while (!in.eof())
	{
		if (count > (arr.getSize()-1))
			break;
		in.getline(buffer, 100);	// һ��һ�еض�
		Student stu;
		stu.loadFromString(buffer);
		arr[count++] = stu;
	}

	in.close();								//  �ǳ���Ҫ
}