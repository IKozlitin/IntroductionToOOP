#include<iostream>
using namespace std;

#define WIDTH 22

class String
{
	size_t size;		//размер строки в Байтах
						//size_t - unsigned int
	char* str;			//адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	size_t get_size()const
	{
		return size;
	}
	//						Constructors:
	explicit String(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout.width(WIDTH);
		cout << left << "DefaultConstructor: " << this << endl;
	}
	String(const char* str)

	{
		this->size = strlen(str) +1;		//strlen() - возвращает размер строки в символах
											//+1 - резервирует место для NULL-терминатора
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout.width(WIDTH);
		cout << left << "Constructor: " << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout.width(WIDTH);
		cout << left << "Copy constructor: " << this << endl;
	}	
	~String()
	{
		delete[] this->str;
		cout.width(WIDTH);
		cout << left << "Destructor: " << this << endl;
	}
	

	//						Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

};

String operator+(const String& left, const String& right)
{
	String str(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		str.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		str.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return str;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "Rus");
	
	//String str1 = 12;	//explicit constructor нельзя вызвать так
	String str0(12);	//explicit constructor можно вызвать только так
	str0.print();

	String str1 = "Hello";
	str1.print();
	cout << typeid("Hello").name() << endl;

	String str2 = "World";
	str2.print();

	String str3 = str1 + str2;
	//str3.print();
	cout << str3 << endl;
}