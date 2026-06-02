#include <iostream>
#include <string>
#include <cmath>

#include <Windows.h>

void printPyramidElementInfo(int level, std::string type, int parentValue, int currentValue) {
	std::cout << level << " " << type << "(" << parentValue << ") " << currentValue << "\n";
}

void printPyramid(int* arr, int size) {
	
	//print base array
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i];
		if (i != size - 1)
			std::cout << " ";
	}
	std::cout << "\n";



	//print pyramid
	int level{}, parentValue{};
	std::string type{"root"};
	
	std::cout << "Пирамида:\n";
	for (int i = 0; i < size; ++i) {
		if (i == 0) {
			std::cout << level << " " << type << " " << arr[0] << "\n"; // root
			continue;
		}
		//calculate level
		level = floor(log2(i+1));
		//calculate type
		if (i % 2 == 0) {
			type = "right";
		}
		else {
			type = "left";
		}
		//calculate parentValue
		int parentIndex = (i - 1) / 2;
		parentValue = arr[parentIndex];
		printPyramidElementInfo(level, type, parentValue, arr[i]);
	}
	

}
//1 left(1) 3
//1 - уровень, left/right - сторона, (1) - это родитель, 3 - значение элемента

int main() {
	SetConsoleOutputCP(1251);
	
	int array[6]{ 1, 3, 6, 5, 9, 8 };
	int array2[8]{ 94, 67, 18, 44, 55, 12, 6, 42 };
	int array3[10]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	
	printPyramid(array,6);
	std::cout << "\n\n";
	
	printPyramid(array2, 8);
	std::cout << "\n\n";
	
	printPyramid(array3, 10);
	return 0;
}
