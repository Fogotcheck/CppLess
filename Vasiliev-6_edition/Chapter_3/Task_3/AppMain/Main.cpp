#include "Main.h"
#include <ctime>

using namespace std;

#define ROWS 5
#define COLS 5

void FillArrRandomNum(uint32_t **array, size_t rows, size_t cols);
void PrintMatrices(uint32_t **array, size_t rows, size_t cols);
void TransposMatrices(uint32_t **array, size_t rows, size_t cols);

int main(void)
{
	cout << "Program for transposing matrices." << endl;
	uint32_t **array = new uint32_t *[ROWS];
	if (array == NULL) {
		return -1;
	}

	for (size_t i = 0; i < ROWS; i++) {
		array[i] = new uint32_t[COLS];
		if (array[i] == NULL) {
			while (i) {
				i--;
				delete[] array[i];
			}
			delete[] array;
			return -1;
		}
	}

	FillArrRandomNum(array, ROWS, COLS);

	cout << "Before::" << endl;
	PrintMatrices(array, ROWS, COLS);
	TransposMatrices(array, ROWS, COLS);
	cout << "After::" << endl;
	PrintMatrices(array, ROWS, COLS);

	for (size_t i = 0; i < ROWS; i++) {
		delete[] array[i];
	}
	delete[] array;
	return 0;
}

void FillArrRandomNum(uint32_t **array, size_t rows, size_t cols)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			array[i][j] = rand() % 4096;
		}
	}
}

void TransposMatrices(uint32_t **array, size_t rows, size_t cols)
{
	if (rows != cols) {
		cout << "Errors::" << rows << "!=" << cols << endl;
		return;
	}

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (i <= j) {
				continue;
			}
			swap(array[i][j], array[j][i]);
		}
	}
}

void PrintMatrices(uint32_t **array, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << "[" << i << "]" << "[" << j << "]:" << "0x"
			     << hex << setfill('0') << setw(4) << array[i][j]
			     << "\t";
		}
		cout << endl;
	}
}
