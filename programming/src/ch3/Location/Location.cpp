#include "Object.h"
#include "StackObject.h"
#include "HeapObject.h"

/*
	�޶�������������	
*/

// ���Ǹ�ȫ�ֵĶ���ָ��
Object * pObj = NULL; // nullptr

void init_object()
{
	Object obj("Apple");		// ջ�϶���
	obj.show();

	pObj = new Object("Orange"); // ���϶���
}

void test_object()
{
	init_object();
//	obj.show();					// dumb !
	pObj->show();
	delete pObj;
	pObj = NULL;
}

void test_stackobject()
{
	// �޷��ڶ���ʹ���ˣ� (2)����Ч�������޷�ͨ��

	StackObject so("Milk");							// (1)

 // StackObject * pOs = new StackObject("Milk");    // (2)
}

void test_heapObject()
{
	// �޷���ջ��ʹ��, (1)��Ч�������޷�ͨ��
	// HeapObject car("Benz");									// (1)
	// car.show();

	HeapObject * product = HeapObject::produceObject("BMW"); // (2)
	product->show();
	delete product;
	product = NULL;
}

int main()
{
	test_object();
	test_stackobject();
	test_heapObject();
	system("pause");
    return 0;
}

