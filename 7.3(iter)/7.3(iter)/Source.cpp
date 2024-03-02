// Lab_7_3_iter.cpp
// Варіант 18
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void PrintRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo) {
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void ZeroCol(int** a, const int rowCount, bool& result, int colNo, int rowNo, int& k_zero) {
    if (a[rowNo][colNo] == 0) {
        result = true;
        k_zero++;
    }
    else if (rowNo < rowCount - 1)
        ZeroCol(a, rowCount, result, colNo, rowNo + 1, k_zero);
}

void CountCols(int** a, const int rowCount, const int colCount, int& count, bool& result, int colNo) {
    int k_zero = 0;
    ZeroCol(a, rowCount, result, colNo, 0, k_zero);
    if (k_zero > 0) {
        for (int i = 0; i < rowCount; ++i) {
            if (a[i][colNo] > 0)
                count++;
        }
    }
    if (colNo < colCount - 1)
        CountCols(a, rowCount, colCount, count, result, colNo + 1);
}

void LongestSeries(int** a, const int rowCount, const int colCount) {
    int maxSeriesCount = 0;
    int maxSeriesColumn = -1;

    for (int j = 0; j < colCount; ++j) {
        int currentSeriesCount = 1;
        for (int i = 0; i < rowCount - 1; ++i) {
            if (a[i][j] == a[i + 1][j]) {
                currentSeriesCount++;
            }
            else {
                if (currentSeriesCount > maxSeriesCount) {
                    maxSeriesCount = currentSeriesCount;
                    maxSeriesColumn = j;
                }
                currentSeriesCount = 1;
            }
        }

        if (currentSeriesCount > maxSeriesCount) {
            maxSeriesCount = currentSeriesCount;
            maxSeriesColumn = j;
        }
    }

    if (maxSeriesColumn != -1) {
        cout << "The longest series of identical elements occurs in a column " << maxSeriesColumn + 1 << " and has length " << maxSeriesCount << endl;
    }
    else {
        cout << "The matrix does not have the same elements in the columns." << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -7;
    int High = 7;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
    PrintRows(a, rowCount, colCount, 0);

    int count = 0;
    bool result = false;
    CountCols(a, rowCount, colCount, count, result, 0);
    if (result)
        cout << "Number of positive elements in columns with at least one zero element: " << count << endl;
    else
        cout << "There are no zero elements in the matrix." << endl;

    LongestSeries(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
