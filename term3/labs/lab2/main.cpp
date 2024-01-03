#include "String.h"
#include <vector>


int main() {

	String str1;
	String str2;

	std::cout << "Input str1: ";
	std::cin >> str1;
	std::cout << "Input str2: ";
	std::cin >> str2;

	std::cout << "str1: " << str1 << std::endl;
	std::cout << "str2: " << str2 << std::endl;

	//String result = "FKSiS" + str1 + str2 + "250501";
	//std::cout << "str1 + str2: " << result << std::endl;

	bool check;
	check = (str1 < str2);
	std::cout << "str1 < str2: " << check << std::endl;
	check = (str1 > str2);
	std::cout << "str1 > str2: " << check << std::endl;

	str1 += str2;
	std::cout << "str1 += str2: " << str1 << std::endl;

	String substring = str1(0,1);
	std::cout << "str1(0, 1): " << substring << std::endl;

	++str1;
	std::cout << "++str1: " << str1 << std::endl;
	str1++;
	std::cout << "str1++: " << str1 << std::endl;
	
	--str1;
	std::cout << "--str1: " << str1 << std::endl;

}