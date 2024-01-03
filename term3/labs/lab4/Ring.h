#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Educator.h"

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

	Element<T>* Current;	// ��������� �� ������� �������
	Element<T>* Head;		// ��������� �� ������ �������

public:

	int length;

	Ring();
	Ring(T);
	Ring(const Ring<T>&);
	~Ring();


	void init();				// ������� ������� ��������� �� ������
	void push(T);				// �������� ����� ������� � ������
	T pop();					// ���������� �������� ��������

	void deleteElement(T dataToDelete);  // ������� �� ������ ��������� �������
	bool contains(T dataToFind);  // �������� �� ������ ��������� �������?

	void next();				// ������� � ���������� ��������
	void prev();				// ������� � ����������� ��������
	void print();				// ������� �� ������ � �������
	void clear();				// �������� �� ������
	int isEmpty();				// �������� ��������� ������ (���� ������ �� ����)
};

template class Ring<int>;
template class Ring<String>;
template class Ring<Educator>;