#include <iostream>
#include <vector>
#include <iomanip>

#include "/My projects/lab3/lab3/String.h"
#include "/My projects/Exceptions/Exceptions/InputException.h"

#pragma once

class Human {

protected:

	String name;
	int birthYear;

public: 

	Human();
	Human(const String& name, int birthYear);
	Human(const char name[], int birthYear);
	virtual ~Human();

	String getName() const;
	int getBirthYear() const;
	void setName(const String& name);
	void setName(const char* name);
	void setBirthYear(int birthYear);

	Human& operator=(const Human& other);
	friend std::ostream& operator<<(std::ostream& os, const Human& human);
	friend std::istream& operator>>(std::istream& is, Human& human);

	static void classView();
};

#include "../lab3/Human.inl"