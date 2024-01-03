#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Educator.h"

#pragma once

template <class T>
struct Element {

	T data;					// переменная необходимая для хранения данных в элементе кольца
	Element* next;			// указатель на следующий элемент
	Element* prev;			// указатель на предыдущий элемент
};

template <class T>
class Ring {				// шаблон класса Кольцо

private:

	Element<T>* Current;	// указатель на текущий элемент
	Element<T>* Head;		// указатель на первый элемент

public:

	int length;

	Ring();
	Ring(T);
	Ring(const Ring<T>&);
	~Ring();


	void init();				// текущий элемент ссылается на первый
	void push(T);				// добавить новый элемент в кольцо
	T pop();					// извлечение текущего элемента

	void deleteElement(T dataToDelete);  // удалить из кольца введенный элемент
	bool contains(T dataToFind);  // содержит ли кольцо введенный элемент?

	void next();				// перейти к следующему элементу
	void prev();				// перейти к предыдущему элементу
	void print();				// вывести всё кольцо в консоль
	void clear();				// очистить всё кольцо
	int isEmpty();				// проверка состояния кольца (если список не пуст)
};

template class Ring<int>;
template class Ring<String>;
template class Ring<Educator>;