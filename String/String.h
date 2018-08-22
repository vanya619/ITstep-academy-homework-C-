#include <iostream>
using namespace std;
#define ASCII_DIFFERENCE 32

class String
{
private:
	char* string;
	int size;

public:
	String(const char*);
	char* Str();
	int Len();
	void AddStr(const char* str);
	void Change(const char*);
	void StrASCII();
	void PasteSymb(int, char);
	void StrU();
	void StrL();
	~String();
};

String::String(const char* str)
{
	size = strlen(str) + 1;
	string = new char[size];
	strcpy_s(string, size, str);
}


inline char* String::Str()
{
	return string;
}

inline int String::Len()
{
	return strlen(string);
}

void String::AddStr(const char* str)
{
	size = strlen(string) + strlen(str) + 1;
	char* buff = string;
	string = new char[size];
	strcpy_s(string, size, buff);
	delete[] buff;
	strcat_s(string, size, str);
}

void String::Change(const char* str)
{
	int len = strlen(str) + 1;
	delete[] string;
	string = new char[len];
	size = len;
	strcpy_s(string, len, str);
}

void String::StrASCII()
{
	for (int i = 0; i < size; ++i)
	{
		cout << (int)string[i] << " ";
	}
}

void String::PasteSymb(int position, char symbol)
{
	--position;
	if (position < 0 || position >= size)
	{
		cout << "Error - the entered position is not found";
		return;
	}
	char* buff = string;
	++size;
	string = new char[size];
	string[position] = symbol;
	for (int i = 0; i < size; ++i)
	{
		if (i == position)
			continue;
		if (i >= position)
			string[i] = buff[i - 1];
		else
			string[i] = buff[i];
	}
	delete[] buff;
}

void String::StrU()
{
	for (int i = 0; i < size; ++i)
	{
		if (string[i] == '\0')
			break;
		if (string[i] >= 'a' && string[i] <= 'z')
			cout << (char)(string[i] - ASCII_DIFFERENCE) << "";
		else
			cout << string[i] << "";
	}
}

void String::StrL()
{
	for (int i = 0; i < size; ++i)
	{
		if (string[i] == '\0')
			break;
		if (string[i] >= 'A' && string[i] <= 'Z')
			cout << (char)(string[i] + ASCII_DIFFERENCE) << "";
		else
			cout << string[i] << "";
	}
}

String::~String()
{
	delete[] string;
}
