#include<iostream>
using namespace std;

//#define CONSTRUCTORS_CHECK
//#define METHODS_CHECK
#define OPERATORS_CHECK

class Fraction;

Fraction operator+(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;	//целая часть
	int numerator;	//числитель
	int denominator;//знаменатель
public:
	const int& get_integer() const
	{
		return integer;
	}
	int& get_integer()
	{
		return integer;
	}
	const int& get_numerator() const
	{
		return numerator;
	}
	int& get_numerator()
	{
		return numerator;
	}
	const int& get_denominator()const
	{
		return denominator;
	}
	int& get_denominator()
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//			Constructor:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstr:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this+other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this=*this*other;
	}

	//			Increment/Decrement:
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp = *this;	//сохраняем значение, которое нужно вернуть 
								//(текущее состояние объекта).
		this->integer++;
		return temp;
	}

	//			Arithmetical operators:
	/*Fraction operator*(const Fraction& other) const
	{
		Fraction left = *this;
		Fraction right = other;
		left.to_improper();
		right.to_improper();
		return Fraction(left.numerator*right.numerator, left.denominator*right.denominator).to_proper().reduce();
	}*/


	//			Methods:
	Fraction& to_proper()
	{
		//Переводит дробь в правильную (выделяет целую часть, если она есть):
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//Переводит дробь в неправильную (непристойную) целую часть сливает с числителем:
		numerator += integer * denominator;
		integer -= integer;
		return *this;
	}
	Fraction& reduce()
	{
		//Сокращает дробь.
		//http://www.webmath.ru/poleznoe/formules_12_7.php
		int more;
		int less;
		int reminder;
		if (numerator > denominator)more = numerator,less = denominator;
		else less = numerator, more = denominator;

		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int GCD = more;	//Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator()*right.get_denominator() + right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator()).to_proper().reduce();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_denominator(), left.get_denominator()*right.get_numerator()).to_proper().reduce();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer() != 0)os << obj.get_integer();
	if (obj.get_numerator() != 0)
	{
		if (obj.get_integer() != 0)os << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)	os << 0;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A(2, 3, 4);
	cout << A << endl;
	Fraction B = A;	//Copy constructor
	cout << B << endl;
	Fraction C;	//Default constructor
	C = B;	//Copy assignment
	cout << (C++) << endl;
	/*Fraction D = C++;
	cout << D << "\t" << C << endl;*/
	cout << (A == B) << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef METHODS_CHECK
	Fraction A(3600, 840);
	//cout << A.to_proper() << endl;
	cout << A.reduce() << endl;
#endif // METHODS_CHECK

#ifdef OPERATORS_CHECK
	int a = 2;
	int b = 3;
	a *= b;

	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	cout << "\n--------------------------------------------------------\n";
	//cout << A + B << endl;
	cout << "\n--------------------------------------------------------\n";
	A += B;
	cout << A.to_improper() << endl;
	cout << B.to_improper() << endl;
	cout << "\n--------------------------------------------------------\n";
#endif // OPERATORS_CHECK


}