#include "Stroka.h"
#include <iostream>
#include <cstring>  // для strlen, strcpy

using namespace std;

// Прототипы ваших пользовательских функций (из лабораторной 4)
int dlina1(char *);
void kopir(char *, char *);
int sravn(char *, char *);
char* konkat(char *, char *);

// ========== РЕАЛИЗАЦИЯ ВАШИХ ФУНКЦИЙ (из лаб. работы 4) ==========

int dlina1(char *str) {
    char *firstSymbolPtr = str;
    while (*str != '\0') {
        str++;
    }
    return str - firstSymbolPtr;
}

void kopir(char *strDest, char *strSource) {
    while (*strSource != '\0') {
        *strDest = *strSource;
        strSource++;
        strDest++;
    }
    *strDest = '\0';
}

int sravn(char *str1, char *str2) {
    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
        str1++;
        str2++;
    }
    
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    }
    else if (*str1 > *str2) {
        return 1;
    }
    else {
        return -1;
    }
}

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

// ========== РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА ==========

// Конструктор по умолчанию (пустая строка)
Stroka::Stroka() {
    str = new char[1];
    str[0] = '\0';
    length = 0;
    cout << "Конструктор по умолчанию: создана пустая строка" << endl;
}

// Конструктор из C-строки
Stroka::Stroka(char *string) {
    length = dlina1(string);
    str = new char[length + 1];
    kopir(str, string);
    cout << "Конструктор из C-строки: \"" << str << "\"" << endl;
}

// НОВЫЙ КОНСТРУКТОР: создает строку заданного размера (для пункта 4)
Stroka::Stroka(int size) {
    if (size > 0) {
        str = new char[size + 1];
        str[0] = '\0';  // пустая строка
        length = 0;
        cout << "Конструктор с размером: выделено " << size + 1 << " байт" << endl;
    } else {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }
}

// Конструктор копирования (глубокое копирование)
Stroka::Stroka(const Stroka& s) {
    length = s.length;
    str = new char[length + 1];
    kopir(str, s.str);
    cout << "Конструктор копирования: \"" << str << "\"" << endl;
}

// Деструктор (освобождает динамическую память)
Stroka::~Stroka() {
    cout << "Деструктор: удаляется строка \"" << str << "\"" << endl;
    delete[] str;
}

// Оператор присваивания (с защитой от самоприсваивания)
Stroka& Stroka::operator=(const Stroka& s) {
    cout << "Оператор присваивания: \"" << str << "\" = \"" << s.str << "\"" << endl;
    
    if (this != &s) {  // Проверка на самоприсваивание
        delete[] str;   // Освобождаем старую память
        
        length = s.length;
        str = new char[length + 1];
        kopir(str, s.str);
    }
    return *this;
}

// Оператор конкатенации (возвращает новый объект)
Stroka Stroka::operator+(const Stroka& s) {
    cout << "Оператор конкатенации: \"" << str << "\" + \"" << s.str << "\"" << endl;
    
    char* temp = konkat(str, s.str);
    Stroka result;
    
    delete[] result.str;
    result.length = dlina1(temp);
    result.str = temp;  // Используем уже выделенную память
    
    return result;
}

// Оператор сравнения
int Stroka::operator==(const Stroka& s) {
    return (sravn(str, s.str) == 0) ? 1 : 0;
}

// Возвращает длину строки
int Stroka::dlina() {
    return dlina1(str);
}

// Ввод строки с клавиатуры
void Stroka::vvod() {
    char buffer[256];
    cout << "Введите строку: ";
    cin >> buffer;
    
    // Перевыделяем память под новую строку
    delete[] str;
    length = dlina1(buffer);
    str = new char[length + 1];
    kopir(str, buffer);
}

// Вывод строки на экран
void Stroka::vyvod() {
    cout << str;
}