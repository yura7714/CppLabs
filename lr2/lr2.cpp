#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#define N 5

using namespace std;

float getMatrixMinimum(float m[N][N]);                          // Минимум всей матрицы
float getMatrixMaximum(float m[N][N]);                          // Максимум всей матрицы
float getMatrixLowTriangularMinimum(float m[N][N]);            // Минимум нижнего треугольника
float getMatrixLowTriangularMaximum(float m[N][N]);            // Максимум нижнего треугольника
float getMatrixUpperTriangularMinimum(float m[N][N]);          // Минимум верхнего треугольника
float getMatrixUpperTriangularMaximum(float m[N][N]);          // Максимум верхнего треугольника
float getMatrixMainDiagonalMinimum(float m[N][N]);             // Минимум главной диагонали
float getMatrixMainDiagonalMaximum(float m[N][N]);             // Максимум главной диагонали
float getMatrixSecondaryDiagonalMinimum(float m[N][N]);        // Минимум побочной диагонали
float getMatrixSecondaryDiagonalMaximum(float m[N][N]);        // Максимум побочной диагонали

float getMatrixArithmeticMean(float m[N][N]);                   // Среднее всей матрицы
float getMatrixLowTriangularArithmeticMean(float m[N][N]);     // Среднее нижнего треугольника
float getMatrixUpperTriangularArithmeticMean(float m[N][N]);   // Среднее верхнего треугольника
void getMatrixRowMeans(float m[N][N], float rowMeans[N]);      // Средние значения строк
void getMatrixColumnMeans(float m[N][N], float columnMeans[N]); // Средние значения столбцов

void getMatrixRowSums(float m[N][N], float rowSums[N]);        // Суммы строк
void getMatrixColumnSums(float m[N][N], float columnSums[N]);  // Суммы столбцов
float getMatrixLowTriangularSum(float m[N][N]);                // Сумма нижнего треугольника
float getMatrixUpperTriangularSum(float m[N][N]);              // Сумма верхнего треугольника

void getMatrixRowMin(float m[N][N], float rowMin[N]);          // Минимумы строк
void getMatrixRowMax(float m[N][N], float rowMax[N]);          // Максимумы строк
void getMatrixColumnMin(float m[N][N], float columnMin[N]);    // Минимумы столбцов
void getMatrixColumnMax(float m[N][N], float columnMax[N]);    // Максимумы столбцов

float getMatrixClosestToMean(float m[N][N]);                   // Элемент, ближайший к среднему

void main()
{
    float m[N][N];
    int i, j;
    
    // Инициализация матрицы случайными числами
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() / 10.;

    // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }
    cout << endl;

    cout << "Min элемент всей матрицы = " << getMatrixMinimum(m) << endl;
    cout << "Max элемент всей матрицы = " << getMatrixMaximum(m) << endl;
    cout << "Min элемент нижнего треугольника = " << getMatrixLowTriangularMinimum(m) << endl;
    cout << "Max элемент нижнего треугольника = " << getMatrixLowTriangularMaximum(m) << endl;
    cout << "Min элемент верхнего треугольника = " << getMatrixUpperTriangularMinimum(m) << endl;
    cout << "Max элемент верхнего треугольника = " << getMatrixUpperTriangularMaximum(m) << endl;
    cout << "Min элемент главной диагонали = " << getMatrixMainDiagonalMinimum(m) << endl;
    cout << "Max элемент главной диагонали = " << getMatrixMainDiagonalMaximum(m) << endl;
    cout << "Min элемент побочной диагонали = " << getMatrixSecondaryDiagonalMinimum(m) << endl;
    cout << "Max элемент побочной диагонали = " << getMatrixSecondaryDiagonalMaximum(m) << endl;
    cout << endl;

    cout << "Среднеарифметическое всей матрицы = " << getMatrixArithmeticMean(m) << endl;
    cout << "Среднеарифметическое нижнего треугольника = " << getMatrixLowTriangularArithmeticMean(m) << endl;
    cout << "Среднеарифметическое верхнего треугольника = " << getMatrixUpperTriangularArithmeticMean(m) << endl;
    cout << endl;

    float rowSums[N];
    getMatrixRowSums(m, rowSums);
    cout << "Суммы строк" << endl;
    for (i = 0; i < N; i++) {
        cout << "Строка " << i << ": " << rowSums[i] << endl;
    }
    cout << endl;

    float columnSums[N];
    getMatrixColumnSums(m, columnSums);
    cout << "Суммы столбцов" << endl;
    for (i = 0; i < N; i++) {
        cout << "Столбец " << i << ": " << columnSums[i] << endl;
    }
    cout << endl;

    float rowMin[N];
    getMatrixRowMin(m, rowMin);
    cout << "Минимумы строк" << endl;
    for (i = 0; i < N; i++) {
        cout << "Строка " << i << ": " << rowMin[i] << endl;
    }
    cout << endl;

    float columnMin[N];
    getMatrixColumnMin(m, columnMin);
    cout << "Минимумы столбцов" << endl;
    for (i = 0; i < N; i++) {
        cout << "Столбец " << i << ": " << columnMin[i] << endl;
    }
    cout << endl;

    float rowMax[N];
    getMatrixRowMax(m, rowMax);
    cout << "Максимумы строк" << endl;
    for (i = 0; i < N; i++) {
        cout << "Строка " << i << ": " << rowMax[i] << endl;
    }
    cout << endl;

    float columnMax[N];
    getMatrixColumnMax(m, columnMax);
    cout << "Максимумы столбцов" << endl;
    for (i = 0; i < N; i++) {
        cout << "Столбец " << i << ": " << columnMax[i] << endl;
    }
    cout << endl;

    float rowMeans[N];
    getMatrixRowMeans(m, rowMeans);
    cout << "Средние арифметические строк" << endl;
    for (i = 0; i < N; i++) {
        cout << "Строка " << i << ": " << rowMeans[i] << endl;
    }
    cout << endl;

    float columnMeans[N];
    getMatrixColumnMeans(m, columnMeans);
    cout << "Средние арифметические столбцов" << endl;
    for (i = 0; i < N; i++) {
        cout << "Столбец " << i << ": " << columnMeans[i] << endl;
    }
    cout << endl;

    cout << "Сумма нижнетреугольной части = " << getMatrixLowTriangularSum(m) << endl;
    cout << "Сумма верхнетреугольной части = " << getMatrixUpperTriangularSum(m) << endl;
    cout << endl;

    cout << "Элемент, наиболее близкий к среднему арифметическому = " 
         << getMatrixClosestToMean(m) << endl;
    cout << endl;
}

// Минимум матрицы
float getMatrixMinimum(float m[N][N]) {
    float minimum = FLT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < minimum) {
                minimum = m[i][j];
            }
        }
    }
    return minimum;
}

// Максимум матрицы
float getMatrixMaximum(float m[N][N]) {
    float maximum = FLT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > maximum) {
                maximum = m[i][j];
            }
        }
    }
    return maximum;
}

// Минимум нижнего треугольника
float getMatrixLowTriangularMinimum(float m[N][N]) {
    float minimum = FLT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < minimum) {
                minimum = m[i][j];
            }
        }
    }
    return minimum;
}

// Максимум нижнего треугольника
float getMatrixLowTriangularMaximum(float m[N][N]) {
    float maximum = FLT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > maximum) {
                maximum = m[i][j];
            }
        }
    }
    return maximum;
}

// Минимум верхнего треугольника
float getMatrixUpperTriangularMinimum(float m[N][N]) {
    float minimum = FLT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < minimum) {
                minimum = m[i][j];
            }
        }
    }
    return minimum;
}

// Максимум верхнего треугольника
float getMatrixUpperTriangularMaximum(float m[N][N]) {
    float maximum = FLT_MIN;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > maximum) {
                maximum = m[i][j];
            }
        }
    }
    return maximum;
}

// Минимум главной диагонали
float getMatrixMainDiagonalMinimum(float m[N][N]) {
    float minimum = FLT_MAX;
    for (int i = 0; i < N; i++) {
        if (m[i][i] < minimum) {
            minimum = m[i][i];
        }
    }
    return minimum;
}

// Максимум главной диагонали
float getMatrixMainDiagonalMaximum(float m[N][N]) {
    float maximum = FLT_MIN;
    for (int i = 0; i < N; i++) {
        if (m[i][i] > maximum) {
            maximum = m[i][i];
        }
    }
    return maximum;
}

// Минимум побочной диагонали
float getMatrixSecondaryDiagonalMinimum(float m[N][N]) {
    float minimum = FLT_MAX;
    for (int i = 0; i < N; i++) {
        if (m[i][N - i - 1] < minimum) {
            minimum = m[i][N - i - 1];
        }
    }
    return minimum;
}

// Максимум побочной диагонали
float getMatrixSecondaryDiagonalMaximum(float m[N][N]) {
    float maximum = FLT_MIN;
    for (int i = 0; i < N; i++) {
        if (m[i][N - i - 1] > maximum) {
            maximum = m[i][N - i - 1];
        }
    }
    return maximum;
}

// Среднее арифметическое всех элементов
float getMatrixArithmeticMean(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Среднее арифметическое элементов нижнетреугольной матрицы
float getMatrixLowTriangularArithmeticMean(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Среднее арифметическое элементов верхнетреугольной матрицы
float getMatrixUpperTriangularArithmeticMean(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Среднее арифметическое строк матрицы
void getMatrixRowMeans(float m[N][N], float rowMeans[N]) {
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        rowMeans[i] = sum / N;
    }
}

// Среднее арифметическое столбцов матрицы
void getMatrixColumnMeans(float m[N][N], float columnMeans[N]) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        columnMeans[j] = sum / N;
    }
}

// Сумма строк матрицы
void getMatrixRowSums(float m[N][N], float rowSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < N; j++) {
            rowSums[i] += m[i][j];
        }
    }
}

// Сумма столбцов матрицы
void getMatrixColumnSums(float m[N][N], float columnSums[N]) {
    for (int j = 0; j < N; j++) {
        columnSums[j] = 0;
        for (int i = 0; i < N; i++) {
            columnSums[j] += m[i][j];
        }
    }
}

// Сумма элементов нижнетреугольной матрицы
float getMatrixLowTriangularSum(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Сумма элементов верхнетреугольной матрицы
float getMatrixUpperTriangularSum(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Минимум в строке
void getMatrixRowMin(float m[N][N], float rowMin[N]) {
    for (int i = 0; i < N; i++) {
        rowMin[i] = FLT_MAX;
        for (int j = 0; j < N; j++) {
            if (m[i][j] < rowMin[i]) {
                rowMin[i] = m[i][j];
            }
        }
    }
}

// Максимум в строке
void getMatrixRowMax(float m[N][N], float rowMax[N]) {
    for (int i = 0; i < N; i++) {
        rowMax[i] = FLT_MIN;
        for (int j = 0; j < N; j++) {
            if (m[i][j] > rowMax[i]) {
                rowMax[i] = m[i][j];
            }
        }
    }
}

// Минимум в столбце
void getMatrixColumnMin(float m[N][N], float columnMin[N]) {
    for (int j = 0; j < N; j++) {
        columnMin[j] = FLT_MAX;
        for (int i = 0; i < N; i++) {
            if (m[i][j] < columnMin[j]) {
                columnMin[j] = m[i][j];
            }
        }
    }
}

// Максимум в столбце
void getMatrixColumnMax(float m[N][N], float columnMax[N]) {
    for (int j = 0; j < N; j++) {
        columnMax[j] = FLT_MIN;
        for (int i = 0; i < N; i++) {
            if (m[i][j] > columnMax[j]) {
                columnMax[j] = m[i][j];
            }
        }
    }
}

// Ближайшее к среднему
float getMatrixClosestToMean(float m[N][N]) {
    float mean = getMatrixArithmeticMean(m);
    float closest = m[0][0];
    float minDiff = abs(m[0][0] - mean);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = abs(m[i][j] - mean);
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}