#ifndef DEF_FRACTION
#define DEF_FRACTION

#include "stdafx.h"
#include <iostream>

class Fraction
{
public:
	Fraction(int numerateur, int denominateur);
	Fraction(int numerateur);
	Fraction();
	void afficher(std::ostream &out) const;
	bool estEgal(const Fraction&)const;
	bool Fraction::operator <(const Fraction &b) const;
	bool Fraction::operator>(const Fraction &b) const;
	bool Fraction::operator==(const Fraction &b) const;
	Fraction operator*(const Fraction&)const;
	Fraction operator+(const Fraction&)const;

private:
	int m_numerateur;
	int m_denominateur;

};

int pgcd(int a, int b);
std::ostream& operator<<(std::ostream& out, Fraction const& Fraction);

#endif