#include "MyVector.h"

MyVector::MyVector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->SetLen();
}

void MyVector::SetLen(void)
{
	this->len = sqrt(x * x + y * y + z * z);
}

void MyVector::SetX(double x)
{
	this->x = x;
	this->SetLen();
}
void MyVector::SetY(double y)
{
	this->y = y;
	this->SetLen();
}
void MyVector::SetZ(double z)
{
	this->z = z;
	this->SetLen();
}

double MyVector::GetLen(void)
{
	return this->len;
}

MyVector MyVector::operator+(const MyVector &other) const
{
	return MyVector((x + other.x), (y + other.y), (z + other.z));
}
MyVector MyVector::operator-(const MyVector &other) const
{
	return MyVector((x - other.x), (y - other.y), (z - other.z));
}
MyVector MyVector::operator*(const MyVector &other) const
{
	return MyVector((y * other.z -
			 z * other.y), // x-координата векторного произведения
			(z * other.x -
			 x * other.z), // y-координата векторного произведения
			(x * other.y -
			 y * other.x) // z-координата векторного произведения
	);
}

double MyVector::GetAngle(const MyVector &other) const
{
	if (len * other.len == 0) {
		throw std::invalid_argument("Division by zero");
	}
	return acos((this->GetDotProduct(other)) / (len * other.len));
}

double MyVector::GetAngle(const MyVector &other, int _base) const
{
	if (len * other.len == 0) {
		throw std::invalid_argument("Division by zero");
	}
	double res = acos((this->GetDotProduct(other)) / (len * other.len));
	switch (_base) {
	case RAD:
		break;
	case DEGREEDS:
		res *= (180.0 / M_PI);
		break;
	default:
		throw std::invalid_argument("Unknown data type");
	}

	return res;
}

double MyVector::GetDotProduct(const MyVector &other) const
{
	return (x * other.x + y * other.y + z * other.z);
}

std::ostream &operator<<(std::ostream &os, const MyVector &c)
{
	os << '(' << c.x << ',' << c.y << ',' << c.z << ')';
	return os;
}
