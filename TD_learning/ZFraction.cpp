#include "stdafx.h"
#include <iostream>
#include <ostream>
#include "ZFraction.h"

using namespace std;

int pgcd(int m_numerateur, int m_denominateur)
{
	while (m_denominateur != 0)
	{
		const int t = m_denominateur;
		m_denominateur = m_numerateur%m_denominateur;
		m_numerateur = t;
	}
	return m_numerateur;
}

Fraction::Fraction(int numerateur, int denominateur) : m_numerateur(numerateur/int(pgcd(numerateur,denominateur))), m_denominateur(denominateur/ int(pgcd(numerateur, denominateur)))
{
}

Fraction::Fraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1)
{
}

Fraction::Fraction() : m_numerateur(0), m_denominateur(1)
{
}

void Fraction::afficher(ostream &out) const
{
	out << m_numerateur << "/" << m_denominateur;
}

ostream& operator<<(ostream& out, Fraction const& Fraction)
{
	Fraction.afficher(out);
	return out;
}

Fraction Fraction::operator*(const Fraction& c) const
{
	Fraction result;
	result.m_numerateur = m_numerateur*c.m_numerateur;
	result.m_denominateur = m_denominateur*c.m_denominateur;
	return result;
}

Fraction Fraction::operator+(const Fraction& c) const
{
	Fraction copie;
	if (m_denominateur < c.m_denominateur)
	{
		copie.m_denominateur = m_denominateur * c.m_denominateur;
		copie.m_numerateur = m_numerateur * c.m_denominateur + c.m_numerateur * m_denominateur;
	}
	else
	{
		copie.m_denominateur = c.m_denominateur * m_denominateur;
		copie.m_numerateur = c.m_numerateur* m_denominateur + m_numerateur*c.m_denominateur;
	}
	return copie;
}

bool Fraction::operator==(const Fraction &b) const
{
	return (m_numerateur / m_denominateur == b.m_numerateur / b.m_denominateur);
}
bool Fraction::operator<(const Fraction &b) const
{
	return (m_numerateur / m_denominateur < b.m_numerateur / b.m_denominateur);
}

bool Fraction::operator>(const Fraction &b) const
{
	return (m_numerateur / m_denominateur > b.m_numerateur / b.m_denominateur);
}