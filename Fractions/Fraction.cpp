#include "Fraction.h"

mathlib::Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator cannot be zero.");
	}
	this->denominator = denominator;
	reduce();
}

mathlib::Fraction::Fraction(const Fraction& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}

mathlib::Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}

mathlib::Fraction::~Fraction()
{

}

int mathlib::Fraction::getNumerator() const
{
	return numerator;
}

int mathlib::Fraction::getDenominator() const
{
	return denominator;
}

void mathlib::Fraction::setNumerator(int numerator)
{
	this->numerator = numerator;
	reduce();
}

void mathlib::Fraction::setDenominator(int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator cannot be zero.");
	}
	this->denominator = denominator;
	reduce();
}

mathlib::Fraction mathlib::Fraction::operator+(const Fraction& other) const
{
	return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

mathlib::Fraction mathlib::Fraction::operator-(const Fraction& other) const
{
	return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

mathlib::Fraction mathlib::Fraction::operator*(const Fraction& other) const
{
	return Fraction(numerator * other.numerator, denominator * other.denominator);
}

mathlib::Fraction mathlib::Fraction::operator/(const Fraction& other) const
{
	if (other.numerator == 0)
	{
		throw std::invalid_argument("Cannot divide by zero.");
	}
	return Fraction(numerator * other.denominator, denominator * other.numerator);
}

mathlib::Fraction& mathlib::Fraction::operator=(const Fraction& other)
{
	if (this != &other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	return *this;
}

bool mathlib::Fraction::operator==(const Fraction& other) const
{
	return numerator * other.denominator == other.numerator * denominator;
}

bool mathlib::Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other);
}

bool mathlib::Fraction::operator<(const Fraction& other) const
{
	return numerator * other.denominator < other.numerator * denominator;
}

bool mathlib::Fraction::operator<=(const Fraction& other) const
{
	return *this < other || *this == other;
}

bool mathlib::Fraction::operator>(const Fraction& other) const
{
	return !(*this <= other);
}

bool mathlib::Fraction::operator>=(const Fraction& other) const
{
	return !(*this < other);
}

void mathlib::Fraction::reduce()  
{  
int gcdValue = gcd(numerator, denominator);  
numerator /= gcdValue;  
denominator /= gcdValue;  
if (denominator < 0)  
{  
	numerator = -numerator;  
	denominator = -denominator;  
}  
}

std::ostream& mathlib::operator<<(std::ostream& os, const Fraction& fraction)
{
	os << fraction.numerator << "/" << fraction.denominator;
	return os;
}

//std::istream& mathlib::operator>>(std::istream& is, Fraction& fraction)  
//{  
//char slash;  
//is >> fraction.numerator >> slash >> fraction.denominator;  
//
//if (is.fail() || slash != '/') {  
//	is.setstate(std::ios::failbit);  
//	return is;  
//}  
//
//if (fraction.denominator == 0) {  
//	throw std::invalid_argument("Denominator cannot be zero.");  
//}  
//
//fraction.reduce();  
//return is;  
//}

