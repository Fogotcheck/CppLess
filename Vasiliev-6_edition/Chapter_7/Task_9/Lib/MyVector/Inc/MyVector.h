#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

enum MyVectorBase { RAD, DEGREEDS };

class MyVector {
    private:
	double len;
	double x, y, z;
	void SetLen(void);

    public:
	MyVector(double x = 0, double y = 0, double z = 0);
	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);
	MyVector operator+(const MyVector &other) const;
	MyVector operator-(const MyVector &other) const;
	MyVector operator*(const MyVector &other) const;

	double GetDotProduct(const MyVector &other) const;
	double GetAngle(const MyVector &other) const;
	double GetAngle(const MyVector &other, int _base) const;
	double GetLen(void);

	friend std::ostream &operator<<(std::ostream &os, const MyVector &c);
};
