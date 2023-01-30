#include <iostream>

int checkMaxCount(const int array[], int arraySize);
void arrPrinter(const int array[], int arraySize);

int main() {
    int RANDOM_ARR_SIZE;
    const int EMBEDDED_ARR_SIZE = 10;
    const int embeddedArr1[EMBEDDED_ARR_SIZE]{0, 2, 5, 4, 5, 2, -3, 3, 0, 3};
    const int embeddedArr2[EMBEDDED_ARR_SIZE]{-1, -100, -1, -100, -3, -2, -3, -5, -5, -1};
    const int embeddedArr3[EMBEDDED_ARR_SIZE]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << "Введите размер массива случайных чисел: ";
    std::cin >> RANDOM_ARR_SIZE;

    int *randomArr = new int[RANDOM_ARR_SIZE];
    for (int i = 0; i < RANDOM_ARR_SIZE; ++i) {
        randomArr[i] = rand() % 100;
    }

    std::cout << "Массив 1: \n";
    arrPrinter(const_cast<int *>(embeddedArr1), EMBEDDED_ARR_SIZE);
    std::cout << checkMaxCount(const_cast<int *>(embeddedArr1), EMBEDDED_ARR_SIZE) << "\n";

    std::cout << "Массив 2: \n";
    arrPrinter(const_cast<int *>(embeddedArr2), EMBEDDED_ARR_SIZE);
    std::cout << checkMaxCount(const_cast<int *>(embeddedArr2), EMBEDDED_ARR_SIZE) << "\n";

    std::cout << "Массив 3: \n";
    arrPrinter(const_cast<int *>(embeddedArr3), EMBEDDED_ARR_SIZE);
    std::cout << checkMaxCount(const_cast<int *>(embeddedArr3), EMBEDDED_ARR_SIZE) << "\n";

    std::cout << "Рандомный массив: \n";
    arrPrinter(const_cast<int *>(randomArr), RANDOM_ARR_SIZE);
    std::cout << checkMaxCount(const_cast<int *>(randomArr), RANDOM_ARR_SIZE) << "\n";

    delete[] randomArr;
    return 0;
}

int checkMaxCount(const int array[], const int arraySize) {
    int maxNum = array[0];
    int maxIndex = 0;
    bool isRepeat = false;

    for (int i = 1; i < arraySize; ++i) {

        if (array[i] > maxNum) {
            for (int j = i + 1; j < arraySize; ++j) {
                if (array[j] == array[i]) {
                    maxNum = array[i];
                    isRepeat = true;
                    maxIndex = i;
                    break;
                }
            }
        } else if (array[i] == maxNum) {
            isRepeat = true;
        }

    }
    return isRepeat ? maxIndex : -1;
}

void arrPrinter(const int array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}