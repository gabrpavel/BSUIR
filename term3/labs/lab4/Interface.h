#include <iostream>
#include <locale.h>
#include "Ring.h"

#pragma once

enum RingType {

	INT = 1,
	STRING,
	EDUCATOR

};

enum Menu {

	ADD = 1,
	DELETE,
	CHECK,
	SHOW,
	EXIT = 0

};

template<class T>
void menu(Ring<T>& ring);


void Interface();

template <class T> void addElements(Ring<T>& ring);
template <class T> void deleteElement(Ring<T>& ring, T dataToDelete);
template <class T> void checkValue(Ring<T>& ring, T dataToCheck);