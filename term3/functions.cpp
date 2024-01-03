#include "functions.h"
#include "Array.h"

int menu() {

	int userInput;

    std::cout << "Choose option:\n 1. Create new array\n 2. Show array\n 3. Find the intersection of arrays\n 4. Exit\n";
    std::cout << ">> ";
    std::cin >> userInput;
	return userInput;
}