#include<iostream>
using namespace std;

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


	//			Methods:
	void to_proper()
	{
		//Переводит дробь в правильную (выделяет целую часть, если она есть):

	}
	void to_improper()
	{
		//Переводит дробь в неправильную (непристойную) целую часть сливает с числителем:

	}
	void reduce()
	{
		//Сокращает дробь.
		//http://www.webmath.ru/poleznoe/formules_12_7.php
	}
};

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
}