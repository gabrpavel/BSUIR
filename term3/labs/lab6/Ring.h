#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#pragma once

template <class T>
struct Element {

	T data;					// ���������� ����������� ��� �������� ������ � �������� ������
	Element* next;			// ��������� �� ��������� �������
	Element* prev;			// ��������� �� ���������� �������
};

template <class T>
class Ring {				// ������ ������ ������

private:

	Element<T>* Head;		// ��������� �� ������ �������
	int length;

public:

	Ring();
	Ring(T);
	Ring(const Ring<T>&);
	Ring(Ring<T>&& other) noexcept;
	~Ring();
	int getLength();
	T& getAt(int index);
	void push(T);				// �������� ����� ������� � ������
	T pop();					// ���������� �������� ��������

	void deleteElement(T dataToDelete);
	void print();				// ������� ���� ������ � �������
	void clear();				// �������� ���� ������
	bool isEmpty();			// �������� ��������� ������ (���� ������ �� ����)
	bool exist(T data);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Ring<T>& ring);
	bool operator==(const Ring<T>& other) const;
	bool operator!=(const Ring<T>& other) const;
	Ring<T>& operator =(const Ring<T>& other);
	Ring<T>& operator =(Ring<T>&& other) noexcept;

	class Iterator {

	public:

		Element<T>* current;			// ��������� �� ������� ������� 

		Iterator();
		Iterator(Element<T>*);			// ����������� ��� ������� Begin() � End()
		~Iterator();

		T& operator++(int);				// ��������� �� ������ �����
		T& operator--(int);				// ��������� �� ������ �����
		T& operator*();					// �������� ������ �� ���������
		T operator=(const T& value);
		bool operator!=(Iterator);
		bool operator==(Iterator);
	};

	void pop(Iterator it);
	Iterator find(T data);
	Iterator begin();					// ������� ������ ������
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

// ��������� �� ������ �����
template<typename T>
T& Ring<T>::Iterator::operator++(int value)
{
	this->current = current->next;
	return current->data;
}

// ��������� �� ������ �����
template<typename T>
T& Ring<T>::Iterator::operator--(int value)
{
	this->current = current->prev;
	return current->data;
}

// �������� ������ �� ���������
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
// ���������� ��������� !=
template<typename T>
bool Ring<T>::Iterator::operator!=(Iterator other)
{
	return this->current != other.current;
}

// ���������� ��������� ==
template<typename T>
bool Ring<T>::Iterator::operator==(Iterator other)
{
	return !(*this == other);
}

// ������� ������ ������
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