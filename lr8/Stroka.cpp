#include "Stroka.h"
#include <iostream>

using namespace std;

int dlina1(char *);
void kopir(char *, char *);
int sravn(char *, char *);
char* konkat(char *, char *);

// Конструкторы
Stroka::Stroka(char *string) {
    int length = dlina1(string);
    str = new char[length + 1];
    kopir(str, string);
}

Stroka::Stroka(const Stroka& s) {
    int length = dlina1(s.str);
    str = new char[length + 1];
    kopir(str, s.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Переопределение оператора присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {  // Защита от присваивания самому себе
        delete[] str;  // Освобождаем старую память
        
        int length = dlina1(s.str);
        str = new char[length + 1];  // Выделяем новую
        kopir(str, s.str);
    }
    return *this;
}

// Переопределение конкатенации строк
Stroka Stroka::operator+(const Stroka& s) {
    return Stroka(konkat(str, s.str));
}

//Переопределение сравнения
int Stroka::operator==(const Stroka& s) {
    if ((sravn(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

istream& operator>>(istream& is, Stroka& s) {
    char buffer[256];
    is >> buffer;

    delete[] s.str;
    
    int length = dlina1(buffer);
    s.str = new char[length + 1];
    kopir(s.str, buffer);

    return is;
}

ostream& operator<<(ostream& os, const Stroka& s) {
    os << s.str;
    return os;
}

// Длина строки
int Stroka::dlina() {
    return dlina1(str);
}

// Ввод строки
void Stroka::vvod() {
    char buffer[256];
    cout << "Введите строку: ";
    cin >> buffer;
    
    int length = dlina1(buffer);
    str = new char[length + 1];
    kopir(str, buffer);
}

// Вывод строки
void Stroka::vyvod() {
    cout << str;
}

// Копирование строки
void kopir(char *strDest, char *strSource)
{
    while (*strSource != '\0')
    {
        *strDest = *strSource;
        strSource++;
        strDest++;
    }

    *strDest = '\0';
}

// Конкатенация строк
char* konkat(char* str1, char* str2) {
    const int totalLen = dlina1(str1) + dlina1(str2) + 1;
    char* concatStr = new char[totalLen];
    char* firstBytePtr = concatStr;

    while (*str1 != '\0') {
        *concatStr = *str1;
        str1++;
        concatStr++;
    }

    while (*str2 != '\0') {
        *concatStr = *str2;
        str2++;
        concatStr++;
    }

    *concatStr = '\0';

    return firstBytePtr;
}

// Сравнение строк
int sravn(char *str1, char *str2)
{
    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }
    else if (*str1 > *str2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Длина строки
int dlina1(char *str)
{
    char *firstSymbolPtr = str;

    while (*str != '\0')
    {
        str++;
    }

    return str - firstSymbolPtr;
}