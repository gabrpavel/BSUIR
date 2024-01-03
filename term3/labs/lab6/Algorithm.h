#pragma once
#include <algorithm>
#include<functional>
#include <sstream>
#include "D:\My projects\Ring\Ring\Ring.h"

template <class T>
class Algorithm {

public:

	static int partition(Ring<T>& ring, int low, int high, std::function<bool(const T&, const T&)> compare);
	static void quickSortUtil(Ring<T>& ring, int low, int high, std::function<bool(const T&, const T&)> compare);
	static void quickSort(Ring<T>& ring, std::function<bool(const T&, const T&)> compare);
	static void saveInFile(Ring<T>& ring, const char* fileName);
	static void loadFromFile(Ring<T>& ring, const char* fileName, const std::string& target);
	static void removeFromFile(const char* fileName, const T& target);
};

#include "../Ring/Algorithm.inl"