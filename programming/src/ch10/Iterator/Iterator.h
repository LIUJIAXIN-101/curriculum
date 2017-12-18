#pragma once

/*
	������ģʽʾ��
*/

// һ��ģ�廯�ĵ������ӿ�
template <class T>
class Iterator
{	
public:
	virtual T & next() = 0;
	virtual bool hasNext() = 0;
};

// һ��ģ�廯�Ŀ��Խ��е������ʵĽṹ�ӿ�
template <class T>
class Iterable
{
public:
	virtual Iterator<T> * begin() = 0;
};

template <class T>
class ArrayIterator;

// һ���޶���С�Ķ�̬���飺�ɵ�������
template <class T>
class Array : public Iterable<T>
{
public:
	Array(int sz) : size(sz)
	{
		arr = new T[size];
	}
	~Array()
	{
		if (nullptr != arr)
		{
			delete [] arr;
			arr = nullptr;
		}
	}	

	T & get(int i)
	{
		return arr[i];

	}

	Iterator<T> * begin()
	{
		return new ArrayIterator<T>(*this);
	}

	int getSize()
	{
		return size;
	}

	T & operator [](int i)
	{
		return arr[i];
	}
private:
	T * arr;
	int size;
};

// ������Array�ĵ�����
template <class T>
class ArrayIterator : public Iterator<T>
{
public:
	ArrayIterator(Array<T> & a) : arr(a), pos(0) {}
	
	T & next()
	{
		return arr.get(pos ++);
	}
	bool hasNext()
	{
		return pos < arr.getSize();
	}

private:
	Array<T> & arr;
	int pos;
};