#include<iostream>
using namespace std;

//#define CONSTRUCTOR_CHEK
//#define OPERATORS_CHEK
class String;
String operator+(const String& left, const String& right);

class String
{
	int size; //������ ������
	char* str; // ����� ������ � ������������ ������
public:
	int get_size() const;

		const char* get_str() const;

		char* get_str();

		//Constructors:
		String(int size = 80);

		String(const char str[]);

		String(const String& other);

		String(String&& other);

		~String();

		//Operators:
		String& operator=(const String& other);

		String&operator=(String&& other);

		String& operator+=(const String& other);

		char& operator[](int i);

		char operator[](int i) const;

		//Metod:
		void print();

};
int String::get_size() const
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

//Constructors:
String::String(int size = 80) 
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[]) 
size(strlen(str)+1),str(new char[size]{})  
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
	this->str = new char [size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyConstructor:" << this << endl;
}
String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;  //������ ������� ������������
	cout << "MoveConstructor:" << this << endl;
}

~String()
{
	delete[]this->str;
	cout << "Destructor:\t" << this << endl;
}
//Operators:
String& String:: operator=(const String& other)
{
	// 0)��������� �������� �� ��� ������ ���� �������
	if (this == &other) return *this;
	delete[] this->str; //1)������� ������ �������� �������

	//2)�������� ��������� ������� ������ 
	this->size = other.size;
	this->str = new char [size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssigment\t:" << this << endl;
	return *this;
}
String&operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;  //������ ������� ������������
	cout << "MoveAssigment:\t" << this << endl;
	return *this;
}
String& operator+=(const String& other)
{
	return *this = *this + other;
}

char& operator[](int i)
{
	//char value = this->str[i];
	return this->str[i];
}
char operator[](int i) const
{
	//char value = this->str[i];
	return this->str[i];
}

//Metod:
void print()
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat = left.get_size() + right.get_size() - 1;
	//cout << cat.get_size() << endl;
	//for (int i = 0; left.get_str()[i]; i++)
	//	*(cat.get_str() +i) = *(left.get_str() +i);
	//for (int i = 0; right.get_str()[i]; i++)
	//	cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
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

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTOR_CHEK
	cout << typeid("Hello").name() << endl;
	String str1 = "Hello";
	str1.print();
	cout << str1 << endl;
	String str2 = str1;
	cout << str1 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
	cout << "\n------------------------\n";
	str2 = str2;
	cout << str2 << endl;
	cout << "\n------------------------\n";
	/*int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;*/
#endif // CONSTRUCTOR_CHEK
#ifdef OPERATORS_CHEK
	String str1 = "Hello";
	String str2 = "Horld";
	cout << "\n------------------------\n";
	//String str3 = str1 + " " + str2; //MoveConstructor
	cout << "\n------------------------\n";
	String str3;
	str3 = str1 + " " + str2; //MoveAssigment
	cout << str3 << endl;
	str1 += " " + str2;
	cout << str1 << endl;
	// �������� � ����� MoveConstructor MoveAssignment � ��������� �� ������  
#endif // OPERATORS_CHEK
	String str1 = 2;
	cout << str1 << endl;
	String str2 = "Hello";
	cout << str2 << endl;
}