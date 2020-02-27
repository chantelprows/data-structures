#pragma once
#include "QSInterface.h"
#include <array>

class QS : public QSInterface {

public:

	QS();

	~QS();

	void sortAll();

	int medianOfThree(int left, int right);

	int partition(int left, int right, int pivotIndex);

	string getArray() const;

	int getSize() const;

	bool addToArray(int value);

	bool createArray(int capacity);

	void clear();

private:

	void swap(int first, int second);
	void sort(int left, int right);
	int* myArray;
	int newCapacity;
	int currentSize = 0;


};
