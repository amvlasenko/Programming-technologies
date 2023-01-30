#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int** getMatrixFromFile(std::istream &fin, int& matrixSizeToSet) {
    int** result;

    int matrixSize;
    fin >> matrixSize;
    matrixSizeToSet = matrixSize;

    result = new int* [matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        result[i] = new int[matrixSize];
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            fin >> result[i][j];
        }
    }
    return result;
}

void deleteMatrix(int** matrix, const int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, const int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

int findRepeats(int** matrix, const int matrixSize) {
    int withoutRepeats = matrixSize;

    for (int i = 0; i < matrixSize; ++i)	{
        for (int j = 0; j < matrixSize - 1; ++j) {
            if (matrix[j][i] == matrix[j+1][i]) {
                withoutRepeats -= 1;
                break;
            }
        }
    }
    return withoutRepeats;
}

int main() {
    int matrixSize = 0;
    std::ifstream fin;
    fin.open("input.txt");
    while (!fin.eof())
    {
        int** matrix = getMatrixFromFile(fin, matrixSize);

        std::cout << "\n\n" << "--------------------------------------------------------------" << "\n";
        printMatrix(matrix, matrixSize);
        std::cout << "Количество столбцов без повторяющихся элементов: "\
        << findRepeats(matrix, matrixSize) << "\n";
        std::cout << "--------------------------------------------------------------";

        deleteMatrix(matrix, matrixSize);
    }
    fin.close();
    return 0;
}