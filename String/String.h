#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	int size;	//размер строки.
	char* str;	//адрес строки в динамической памяти.
public:
	const int get_size() const;

	const char* get_str() const;

	char* get_str();

	//			Constructors:
	String(int size = 80);

	String(const char str[]);

	String(const String& other);

	String(String&& other);

	~String();

	//			Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	const char& operator[](int i) const;
	char& operator[](int i);
	//			Methods:
	void print();

};