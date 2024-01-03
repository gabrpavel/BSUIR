#include <iostream>
#include <iomanip>
#include <vector>


class Array {

	int* arr; // ��������� �� ������
	int len;  // ����� �������

public:
	
	Array();							// ����������� �� ���������
	Array(int len);						// ����������� � �������� ������
	Array(int* arr, int len);			// ����������� � �������� � ��� ������
	Array(const Array& other);			// ����������� �����������
	~Array(); // ����������

	// ������� � ������� ��� ������� � ����� ������
	void setArr(int* arr); 
	void setLen(int len);  
	int  getLen() const;   
	int* getArr() const;  

	
	void input();						// ���� ������� � ����������
	void show() const;					// ����� ������� �� �����

	// ����������� ����� ��� ���������� ����������� ���� ��������
	static Array findIntersection(const Array& arr1, const Array& arr2);
	//Array findIntersection(Array& arr1);
};
