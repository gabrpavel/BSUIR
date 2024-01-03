#include "Array.h"

// ����������� �� ���������, �������������� ��������� �� ������ ��� nullptr � ����� ��� 0
Array::Array() : arr(nullptr), len(0) {}

// ����������� � �������� ������, �������������� ��������� �� ������ ��� nullptr � ������������� �����
Array::Array(int len) {

	this->len = len;
	arr = new int[len];
	for (int i = 0; i < len; i++)
		this->arr[i] = 0;
}

// ����������� � �������� � ��� ������, �������� ���������� ������ � ������������� �����
Array::Array(int* arr, int len) {
	this->len = len;
	this->arr = new int[len];
	for (int i = 0; i < len; i++)
		this->arr[i] = arr[i];
}

// ����������� �����������, ������� ����� ������ � �������� ������ �� ������� ������� Array
Array::Array(const Array& other) {
	len = other.len;
	arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = other.arr[i];
}

// ����������, ����������� ������, ���������� ��� �������
Array::~Array() {
	delete[] arr;
}


void Array::setArr(int* arr) {
	for (int i = 0; i < len; i++)
		this->arr[i] = arr[i];
}
void Array::setLen(int len) {
	this->len = len;
}
int Array::getLen() const {
	return len;
}
int* Array::getArr() const {
	return arr;
}

// ����� ��� ����� ������ � ������ � ����������
void Array::input() {
	for (int i = 0; i < len; i++)
		std::cin >> arr[i];
}

// ����� ��� ������ ������� �� �����
void Array::show() const {
	for (int i = 0; i < len; i++)
		std::cout << std::setw(5) << arr[i];
	std::cout << std::endl;
}

// ����������� ����� ��� ���������� ����������� ���� ��������
Array Array::findIntersection(const Array& arr1, const Array& arr2) {
	
	int size = 0;
	if (arr1.getLen() >= arr2.getLen()) size = arr2.getLen();
	else size = arr1.getLen();

	Array newArray(size);

	int counter = 0;
	for (int i = 0; i < arr1.getLen(); i++) {
		for (int j = 0; j < arr2.getLen(); j++) {
			if (arr1.getArr()[i] == arr2.getArr()[j]) {
				newArray.arr[counter] = arr1.getArr()[i];
				counter++;
				break;
			}
		}
	}

	if (counter != size) {
		int newSize = size - counter;
		Array resultArray(newSize);
		resultArray.len = newSize;
		for (int i = 0; i < newSize; i++)
			resultArray.arr[i] = newArray.arr[i];
		return resultArray;
	}
	else return newArray;
}
