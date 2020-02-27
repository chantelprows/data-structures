#include "QS.h"


QS::QS() {
	myArray = NULL;
}

QS::~QS() {
	clear();
}


void QS::sortAll() {

	if (currentSize < 0) {
		return;
	}
	sort(0, currentSize - 1);
}

int QS::medianOfThree(int left, int right) {

	if (currentSize < 0) {
		return -1;
	}
	if (left > right || left < 0 || right < left || right > currentSize - 1 || left == right) {
		return -1;
	}

	int pivot = (left + right) / 2;
	if (myArray[left] > myArray[pivot]) {
		swap(left, pivot);
	}
	if (myArray[pivot] > myArray[right]) {
		swap(right, pivot);
	}
	if (myArray[left] > myArray[pivot]) {
		swap(left, pivot);
	}

	getArray();

	return pivot;
}

int QS::partition(int left, int right, int pivotIndex) {

	if (myArray == NULL) {
		return -1;
	}
	if (left == right && right == pivotIndex) {
		return -1;
	}
	if (currentSize < 0 || newCapacity <= 0) {
		return -1;
	}
	if (left < 0 || right < 0) {
		return -1;
	}
	if (right > currentSize - 1) {
		return -1;
	}
	if (left > right) {
		return -1;
	}
	if (pivotIndex > right || pivotIndex < left) {
		return -1;
	}

	swap(left, pivotIndex);

	int up = left + 1;
	int down = right - 1;

	do {
		while ((myArray[up] <= myArray[left]) && (up < right - 1)) {
			up++;
		}

		while ((myArray[down] > myArray[left]) && (down > left)) {
			down--;
		}

		if (up < down) {
			swap(up, down);
		}
	} while (up < down);

	swap(left, down);

	return down;	
}


string QS::getArray() const {
	string tmp = "";

	if (currentSize == 0 || myArray == NULL) {
		return tmp;
	}

	for (int i = 0; i < currentSize; i++) {
		tmp = tmp + to_string(myArray[i]) + ",";
	}

	return tmp.substr(0, tmp.size() - 1);
}

int QS::getSize() const {

	return currentSize;
}

bool QS::addToArray(int value) {
	
	if (currentSize < newCapacity) {
		myArray[currentSize] = value;
		currentSize = currentSize + 1;
		return true;
	}
	else {
		return false;
	}
	
}

bool QS::createArray(int capacity) {

	if (capacity < 0) {
		return false;
	}
	else {
		clear();
		newCapacity = capacity;
		currentSize = 0;
		myArray = new int[newCapacity];
		return true;
	}

}

void QS::clear() {
	if (myArray != NULL) {
		delete[] myArray;
		newCapacity = 0;
		currentSize = 0;
		myArray = NULL;
	}
}

void QS::swap(int first, int second) {
	int tmp = myArray[first];
	myArray[first] = myArray[second];
	myArray[second] = tmp;
}

void QS::sort(int left, int right) {

	if (right - left == 1) {
		if (myArray[right] > myArray[left]) {
			return;
		}
		else {
			swap(right, left);
			return;
		}
	}

	if (right == left) return;

	if (left < 0 || right > currentSize - 1 || right < left || left > right) {
		return;
	}

	int pivot = medianOfThree(left, right);
	int newIndex = partition(left, right, pivot);
	sort(left, newIndex - 1);
	sort(newIndex + 1, right);

}
