#include "MsgObserver.h"

void testObserver()
{
	MsgCenter isdep;

	Student a("����"), b("����"), c("С����");
	Teacher zwl("����ʦ"), yhy("Ҷ��ʦ");
	Staff s("�����");
	isdep.addObserver(a);
	isdep.addObserver(b);
	isdep.addObserver(c);
	isdep.addObserver(zwl);
	isdep.addObserver(yhy);
	isdep.addObserver(s);
	
	isdep.notify(1);
}

int main()
{
	testObserver();
	system("pause");
    return 0;
}

