#include<iostream>

//����m��n�η�  
template<int m, int n>
struct POWER {
	static const int data = m * POWER<m, n - 1>::data;//�ݹ����  
};

//ģ���ػ����ս�ݹ�  
template<int m>
struct POWER<m, 0> {
	static const int data = 1;
};