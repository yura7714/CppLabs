#include <iostream>

using namespace std;

void main(void)
{
    // Объявление переменных и функций
    int i, k, degreeBasis;
    int power(int, int);

    // Ввод основания степени
    cout << "Input basis of the degree: ";
    cin >> degreeBasis;

    // Вычисление степеней введенного основания
    for (i = 0; i < 10; i++)
    {
        k = power(degreeBasis, i);
        cout << "i = " << i << ", k = " << k << endl;
    }
}

int power(int x, int n)
{
    int i, p = 1;

    // Умножение числа n раз - n-я степень числа
    for (i = 0; i < n; i++)
    {
        p *= x;
    }

    return p;
}