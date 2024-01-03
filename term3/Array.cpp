#include "Array.h"

//  онструктор по умолчанию, инициализирует указатель на массив как nullptr и длину как 0
Array::Array() : arr(nullptr), len(0) {}

//  онструктор с заданной длиной, инициализирует указатель на массив как nullptr и устанавливает длину
Array::Array(int len) {

	this->len = len;
	arr = new int[len];
	for (int i = 0; i < len; i++)
		this->arr[i] = 0;
}

//  онструктор с массивом и его длиной, копирует переданный массив и устанавливает длину
Array::Array(int* arr, int len) {
	this->len = len;
	this->arr = new int[len];
	for (int i = 0; i < len; i++)
		this->arr[i] = arr[i];
}

//  онструктор копировани€, создает новый массив и копирует данные из другого объекта Array
Array::Array(const Array& other) {
	len = other.len;
	arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = other.arr[i];
}

// ƒеструктор, освобождает пам€ть, выделенную дл€ массива
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

// ћетод дл€ ввода данных в массив с клавиатуры
void Array::input() {
	for (int i = 0; i < len; i++)
		std::cin >> arr[i];
}

// ћетод дл€ вывода массива на экран
void Array::show() const {
	for (int i = 0; i < len; i++)
		std::cout << std::setw(5) << arr[i];
	std::cout << std::endl;
}

// —татический метод дл€ нахождени€ пересечени€ двух массивов
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
