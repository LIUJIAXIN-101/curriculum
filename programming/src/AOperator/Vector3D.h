#pragma once
#pragma once
#include <cmath>
#include<iostream>

typedef struct Vector3D 
{
	float x, y, z;

	Vector3D() { x = 0; y = 0; z = 0; }
	Vector3D(float x0, float y0, float z0) : x(x0), y(y0), z(z0){}

	// ������� <<
	friend std::ostream& operator<<(std::ostream &os, const Vector3D & v);

	// ���
	float X(Vector3D & v) { return (x * v.x + y * v.y + z * v.z); }

	// ���
	Vector3D operator * (Vector3D & v)
	{
		Vector3D vec;

		vec.x = y * v.z - z * v.y;
		vec.y = z * v.x - x * v.z;
		vec.z = x * v.y - y * v.x;

		return vec;
	}

	// ģ��
	float len()
	{
		return sqrtf(x*x + y*y + z*z);
	}

	// ��һ��
	Vector3D Vector3D::normalize()
	{
		float ln = len();
		if (ln == 0) ln = 1;

		x /= ln;
		y /= ln;
		z /= ln;

		return *this;
	}

	Vector3D operator + (const Vector3D & v)
	{
		Vector3D vec;

		vec.x = x + v.x;
		vec.y = y + v.y;
		vec.z = z + v.z;

		return vec;
	}

	void operator += (const Vector3D & v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

	}

	void operator -= (const Vector3D & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vector3D operator - (const Vector3D & v)
	{
		Vector3D vec;

		vec.x = x - v.x;
		vec.y = y - v.y;
		vec.z = z - v.z;

		return vec;
	}

	// ����
	void operator *= (float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
	}

	// ����
	Vector3D operator * (float scale)
	{
		Vector3D vec;
		vec.x = x * scale;
		vec.y = y * scale;
		vec.z = z * scale;

		return vec;
	}
	// ����
	Vector3D operator /(float scale)
	{
		if (scale != 0.0)
		{
			x = x / scale;
			y = y / scale;
			z = z / scale;
		}
		return *this;
	}

	// ����
	Vector3D operator -(){return Vector3D(-x, -y, -z);}

	Vector3D roll(float angle, float x, float y, float z);

	Vector3D rihgtProduct(float m[3][3]);

} Pos, Dir, Vec;
