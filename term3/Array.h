#include <iostream>
#include <iomanip>
#include <vector>


class Array {

	int* arr; // Указатель на массив
	int len;  // Длина массива

public:
	
	Array();							// Конструктор по умолчанию
	Array(int len);						// Конструктор с заданной длиной
	Array(int* arr, int len);			// Конструктор с массивом и его длиной
	Array(const Array& other);			// Конструктор копирования
	~Array(); // Деструктор

	// Геттеры и сеттеры для доступа к полям класса
	void setArr(int* arr); 
	void setLen(int len);  
	int  getLen() const;   
	int* getArr() const;  

	
	void input();						// Ввод массива с клавиатуры
	void show() const;					// Вывод массива на экран

	// Статический метод для нахождения пересечения двух массивов
	static Array findIntersection(const Array& arr1, const Array& arr2);
	//Array findIntersection(Array& arr1);
};
