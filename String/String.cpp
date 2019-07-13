#include"String.h"

const int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constructors:
String::String(int size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[])
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	//0)Проверяем, является ли тот объект этим объектом:
	if (this == &other)return *this;

	//1) Удаляем старое значение объекта:
	delete[] this->str;

	//2) Копируем значение другого объекта:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i) const
{
	//char value = this->str[i];
	return this->str[i];
}

char& String::operator[](int i)
{
	//char value = this->str[i];
	return this->str[i];
}

//			Methods:
void String::print()
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat = left.get_size() + right.get_size() - 1;
	/*for (int i = 0; left.get_str()[i]; i++)
		*(cat.get_str() + i) = *(left.get_str() + i);
	for (int i = 0; right.get_str()[i]; i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	for (int i = 0; left[i]; i++)
		cat[i] = left[i];
	for (int i = 0; right[i]; i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}