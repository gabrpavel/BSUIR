#include "String.h"

String::String() : str(nullptr), len(0) {}

String::String(const char* str) {

	if (str) {

		len = strlen(str);
		this->str = new char[len + 1];
		strcpy_s(this->str, len + 1, str);

	}
}

String::String(const String& other) {

	if (other.str) {

		len = strlen(other.str);
		this->str = new char[len + 1];
		strcpy_s(this->str, len + 1, other.str);
	
	}
}

String::String(String&& other) noexcept {

	this->len = other.len;
	this->str = other.str;
	other.str = nullptr;
}

String::~String() {
	if(str)	delete[] str;
}

String& String::operator =(const String& other) {

	if (this->str != nullptr) delete[] str;

	len = strlen(other.str);
	this->str = new char[len + 1];
	strcpy_s(this->str, len + 1, other.str);

	return *this;
}

String String::operator +(const String& other) {

	String newObject;

	if(str && other.str) {
		newObject.len = strlen(str) + strlen(other.str);
		newObject.str = new char[newObject.len + 1];
		strcpy_s(newObject.str, newObject.len + 1, str);
		strcat_s(newObject.str, newObject.len + 1, other.str);
	}

	return newObject;
}

bool String::operator ==(const String& other) const {

	if (this->len != other.len) return false;
	for (int i = 0; i < len; i++)
		if (this->str[i] != other.str[i]) return false;
	return true;
}

bool String::operator !=(const String& other) const {
	return !(this->operator==(other));
}

String& String::operator +=(const String& other) {

	if (other.str) {
		char* temp = new char[strlen(str) + strlen(other.str) + 1];
		strcpy_s(temp, strlen(str) + strlen(other.str) + 1, str);
		strcat_s(temp, strlen(str) + strlen(other.str) + 1, other.str);
		if (str) {
			delete[] str;
		}
		str = temp;
		len = strlen(temp);
	}

	return *this;
}

String String::operator++(int) {
	String copy(*this);
    ++(*this);
    return copy;
}

String& String::operator++() {

	if (str) {
		for (int i = 0; i < strlen(str); ++i) {
			str[i]++;
		}
	}
	return *this;
}

String String::operator--(int) {
	String copy(*this);
	--(*this);
	return copy;
}

String& String::operator--() {
	if (str) {
		for (int i = 0; i < strlen(str); ++i) {
			str[i]--;
		}
	}
	return *this;
}

bool String::operator >(const String& other) const {
	return (strcmp(str, other.str) > 0);
}

bool String::operator <(const String& other) const {
	return (strcmp(str, other.str) < 0);
}

String String::operator()(int start, int end) {

	String substring;
	if (str && start >= 0 && end >= start && end < strlen(str)) {
		int len = end - start + 1;
		substring.str = new char[len + 1];
		strncpy_s(substring.str, len + 1, str + start, len);
		substring.str[len] = '\0';
	}
	return substring;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	os << str.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& str) {
	char buffer[80]; 
	is.getline(buffer, sizeof(buffer));
	str = (String)buffer; 
	return is;
}


