#include <iostream>

using namespace std;

void main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int a = 2, b = 5;
    void obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);
    cout << "до обмена: a = " << a << " b = " << b << endl;
    obmen1(a, b);
    cout << "после обмена 1: a = " << a << " b = " << b << endl;
    obmen2(&a, &b);
    cout << "после обмена 2: a = " << a << " b = " << b << endl;
    obmen3(a, b);
    cout << "после обмена 3: a = " << a << " b = " << b << endl;
}

// Передача переменных по значению
void obmen1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "во время обмена 1: a = " << a << " b = " << b << endl;
}

// Передача указателей на переменные
void obmen2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Передача переменных по ссылке
void obmen3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}