#ifndef AAA_HEADER
#define AAA_HEADER

#include <iostream>
#include <string.h>

class String {

	char* str;
	int len;

public:

	String();
	explicit String(const char* str);
	String(const String& other);     //Конструктор копирования
	String(String&& other) noexcept; //Конструктор перемещения
	~String();
	
	String& operator =(const String& other);
	String operator +(const String& other);	
	bool operator ==(const String& other) const;
	bool operator !=(const String& other) const;
	String& operator +=(const String& other);
	String operator ++(int);
	String& operator ++();
	String& operator --();
	String operator --(int);
	bool operator>(const String& other) const;
	bool operator<(const String& other) const;
	String operator()(int start, int end);
	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
};

#endif