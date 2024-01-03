#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#pragma once

template <class T>
struct Element {

	T data;					// переменная необходимая для хранения данных в элементе списка
	Element* next;			// указатель на следующий элемент
	Element* prev;			// указатель на предыдущий элемент
};

template <class T>
class Ring {				// шаблон класса Кольцо

private:

	Element<T>* Head;		// указатель на первый элемент
	int length;

public:

	Ring();
	Ring(T);
	Ring(const Ring<T>&);
	Ring(Ring<T>&& other) noexcept;
	~Ring();
	int getLength();
	T& getAt(int index);
	void push(T);				// добавить новый элемент в список
	T pop();					// извлечение текущего элемента

	void deleteElement(T dataToDelete);
	void print();				// вывести весь список в консоль
	void clear();				// очистить весь список
	bool isEmpty();			// проверка состояния списка (если список не пуст)
	bool exist(T data);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Ring<T>& ring);
	bool operator==(const Ring<T>& other) const;
	bool operator!=(const Ring<T>& other) const;
	Ring<T>& operator =(const Ring<T>& other);
	Ring<T>& operator =(Ring<T>&& other) noexcept;

	class Iterator {

	public:

		Element<T>* current;			// указатель на текущий элемент 

		Iterator();
		Iterator(Element<T>*);			// Конструктор для функций Begin() и End()
		~Iterator();

		T& operator++(int);				// двинуться по кольцу вперёд
		T& operator--(int);				// двинуться по кольцу назад
		T& operator*();					// получить данные по указателю
		T operator=(const T& value);
		bool operator!=(Iterator);
		bool operator==(Iterator);
	};

	void pop(Iterator it);
	Iterator find(T data);
	Iterator begin();					// вернуть начало кольца
};

template<typename T>
Ring<T>::Iterator::Iterator() {
	current = nullptr;
}

template<typename T>
Ring<T>::Iterator::Iterator(Element<T>* current) {
	this->current = current;
}

template<typename T>
Ring<T>::Iterator::~Iterator() {}

// двинуться по кольцу вперёд
template<typename T>
T& Ring<T>::Iterator::operator++(int value)
{
	this->current = current->next;
	return current->data;
}

// двинуться по кольцу назад
template<typename T>
T& Ring<T>::Iterator::operator--(int value)
{
	this->current = current->prev;
	return current->data;
}

// получить данные по указателю
template<typename T>
T& Ring<T>::Iterator::operator*()
{
	return this->current->data;
}
template<typename T>
T Ring<T>::Iterator::operator=(const T& value)
{
	this->current->data = value;
	return value;
}
// перегрузка оператора !=
template<typename T>
bool Ring<T>::Iterator::operator!=(Iterator other)
{
	return this->current != other.current;
}

// перегрузка оператора ==
template<typename T>
bool Ring<T>::Iterator::operator==(Iterator other)
{
	return !(*this == other);
}

// вернуть начало кольца
template<typename T>
typename Ring<T>::Iterator Ring<T>::begin()
{
	if (!isEmpty()) {
		Iterator it(this->Head);
		return it;
	}
}

template <class T>
void Ring<T>::pop(typename Ring<T>::Iterator it) {

	if (isEmpty()) {
		std::cerr << "Error: Cannot pop from an empty ring.\n";
		return;
	}

	Element<T>* temp = it.current;
	T tag = temp->data;

	if (length == 1) {
		Head = nullptr;
	}
	else {
		it++;
		it.current->prev = temp->prev;
		temp->prev->next = it.current;

		if (temp == Head)
			Head = Head->next;
	}

	length--;
	delete temp;
}

#include "../Ring/Ring.inl"