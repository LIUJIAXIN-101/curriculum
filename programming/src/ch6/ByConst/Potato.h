#pragma once
#include <string>
#include <iostream>

class Potato
{
public:
	Potato(std::string n) : name(n), skin("SKIN") {}

	// ���ڲ�������Ŀ������캯��
	Potato(const Potato & other)
	{
		name = other.name;
		skin = other.skin;
		std::cout << "ID(" << this << ")" << name << " <---copied from---" << "ID(" << &other << ")" << other.name << std::endl;
	}

	//Potato operator = (const Potato & other)			 // (1)
	//Potato & operator = (Potato & other)				 // (2)		
	//Potato & operator = (const Potato & other)         // (3)		// �Ƽ���ʽ
	//const Potato & operator = (Potato & other)	     // (4)		// �޶��˲���ʹ�� x = y = z;
	const Potato & operator = (const Potato & other)	 // (5)     // �ֿ����ˣ����ֱȽϺ�
	{
		name = other.name;
		skin = other.skin;
		std::cout << "ID(" << this << ")" << name << " <---assigned from---" << "ID(" << &other << ")" << other.name << std::endl;
		return *this;
	}

	void show()
	{
		
		std::cout << "ID(" << this << "):\t"  << skin <<" "<< name << " potato " <<std::endl;
	}

	void peel()
	{
		skin = "PEELED";
		std::cout << "ID(" << this << "):\t" << name << " potato is peeled" << std::endl;
	}

	void changeName(std::string newName) const;

private:
	std::string name;
	std::string skin;
};
