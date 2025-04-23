#pragma once  
#include <ostream>  
#include <numeric>

namespace mathlib  
{  
class Fraction  
{  
public:  
Fraction(int numerator, int denominator);  
Fraction(const Fraction& other);  
Fraction();  
~Fraction();  
int getNumerator() const;  
int getDenominator() const;  
void setNumerator(int numerator);  
void setDenominator(int denominator);  
Fraction operator+(const Fraction& other) const;  
Fraction operator-(const Fraction& other) const;  
Fraction operator*(const Fraction& other) const;  
Fraction operator/(const Fraction& other) const;  
Fraction& operator=(const Fraction& other);  
bool operator==(const Fraction& other) const;  
bool operator!=(const Fraction& other) const;  
bool operator<(const Fraction& other) const;  
bool operator<=(const Fraction& other) const;  
bool operator>(const Fraction& other) const;  
bool operator>=(const Fraction& other) const;  
friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);  
friend std::istream& operator>>(std::istream& is, Fraction& fraction);  

Fraction Simplify() const  
{  
	int gcdValue = std::gcd(numerator, denominator);  
	return Fraction(numerator / gcdValue, denominator / gcdValue);  
}  

float ToFloat() const  
{  
	return static_cast<float>(numerator) / denominator;  
}  

private:  
int numerator;  
int denominator;  
void reduce();  
};  
};