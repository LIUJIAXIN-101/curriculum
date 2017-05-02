#include "SmartExp.hpp"

#include <stack>

char Precede(char a, char b) { //�ж���������ȼ�

	int i, j;

	char Table[8][8] = {

		{ ' ','+','-','*','/','(',')','=' },
		{ '+','>','>','<','<','<','>','>' },
		{ '-','>','>','<','<','<','>','>' },
		{ '*','>','>','>','>','<','>','>' },
		{ '/','>','>','>','>','<','>','>' },
		{ '(','<','<','<','<','<','=',' ' },
		{ ')','>','>','>','>',' ','>','>' },
		{ '=','<','<','<','<','<',' ','=' }

	};  //���ȼ����

	for (i = 0; i<8; i++)

		if (Table[0][i] == a)  //Ѱ�������a

			break;

	for (j = 0; j<8; j++) //Ѱ�������b

		if (Table[j][0] == b)

			break;

	return Table[j][i];

}

bool Calcu_temp(double a, char theta, double b, double &r) { //�����Ԫ���ʽ��ֵ

	if (theta == '+')

		r = a + b;

	else if (theta == '-')

		r = a - b;

	else if (theta == '*')

		r = a * b;

	else {

		if (fabs(b - 0.0)<1e-8)  //�������Ϊ0�����ش�����Ϣ

			return false;

		else

			r = a / b;

	}
	return true;

}


bool IsOper(char ch) { //�ж��ַ�ch�Ƿ�Ϊ�����

	char ptr[10] = { '+', '-', '*', '/', '(', ')', '=' };

	int i;

	for (i = 0; i<7; i++) {

		if (ch == ptr[i])

			return true;
	}
	return false;
}

bool Calculate(const char *s, double &result) { //������ʽ�Ľ��

	char theta;

	int i = 0, j, point = 0;
	double a, b, r, num = 0;
	std::stack<double> num_stack;  //����ջ
	std::stack<char> oper_stack;  //�����ջ
	oper_stack.push('=');

	while (s[i] != '=' || oper_stack.top() != '=') { //�Ա��ʽa���м���

		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') { //�ַ������ֻ���С����

			num = 0;  //��ʼ������Ϊ0

			point = 0;  //point��������Ƿ����С�����Լ���ǰ����С������xλ��point==10^x

			if (s[i] == '.')
				point = 10;
			else
				num = s[i] - 48;

			j = i + 1;

			while (!IsOper(s[j])) { //����������Ҳ���¼�����֣�ֱ�������ֽ������������Ϊֹ

				if (s[j] == '.') {

					point = 10;

					j++;

					continue;

				}

				if (!point)  //��������

					num = num * 10 + (s[j] - 48);

				else {

					num = num + 1.0 * (s[j] - 48) / point;  //С������

					point *= 10;  //С��λ������һλ

				}

				j++;

			}

			i = j;

			num_stack.push(num);  //��������ѹ��ջ��

		}

		else if (IsOper(s[i])) { //�ַ��������

			switch (Precede(s[i], oper_stack.top())) { //���������ջ��������������ȼ��Ƚϲ�����ش���

			case '<':

				oper_stack.push(s[i++]);

				break;

			case '=':

				oper_stack.pop();

				i++;

				break;

			case '>':

				theta = oper_stack.top();  //��ջ�е���һ����������м���

				oper_stack.pop();

				b = num_stack.top();  //�����������֣�ע��˳���ȵ��������ǵڶ���������

				num_stack.pop();

				a = num_stack.top();

				num_stack.pop();

				if (Calcu_temp(a, theta, b, r))  //���㲢�ж��Ƿ��г�������0�����

					num_stack.push(r);  //���������򽫽��ѹ��ջ��

				else

					return false;  //���ֳ���Ϊ0����������ش�����Ϣ

				break;
			}
		}
	}

	result = num_stack.top();  //�������ջ�е�����Ϊ���ʽ�����ս��

	return true;
}

bool isNumber(char c)
{
	return false;
}

bool Check(const char *s) { //�����ʽ�����Ƿ�ƥ��

	int flag = 0, i;

	for (i = 0; s[i] != 0; i++) {

		if (s[i] == '(')

			flag++;

		if (s[i] == ')')

			flag--;

	}
	if (flag)
		return false;

	return true;
}


double SmartExp::calculate()
{
	double r = 0.0;

	std::string str = exp + "=";

	if (! Check(str.c_str()))
	{
		errInfo = "brackets are not match";
		return r;
	}

	if (! Calculate(str.c_str(), r))
		errInfo = "divided by 0";

	return r;
}

#include <sstream>
std::string double2string(double d)
{
	std::stringstream os;
	os << d;
	return os.str();
}

std::string smartExpCalc(std::string exp)
{
	double r = 0.0;

	std::string str = exp + "=";

	if (! Check(str.c_str()))
		return "brackets are not match";

	if (! Calculate(str.c_str(), r))
		return "divided by 0";

	return double2string(r);
}

const char * getExpCalc(const char * exp)
{
	std::string str = exp;
	std::string res = smartExpCalc(str);

	return res.c_str();
}