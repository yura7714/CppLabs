#ifndef STROKA_H
#define STROKA_H

class Stroka {
    char* str;     // Указатель на динамически выделенную память
    int length;    // Длина строки (для удобства)
    
public:
    // Конструкторы
    Stroka();                           // Конструктор по умолчанию
    Stroka(char*);                      // Конструктор из C-строки
    Stroka(int size);                   // НОВЫЙ: конструктор с заданным размером
    Stroka(const Stroka&);              // Конструктор копирования
    
    // Деструктор (ОБЯЗАТЕЛЕН при динамической памяти)
    ~Stroka();
    
    // Операторы
    Stroka& operator=(const Stroka&);   // Оператор присваивания
    Stroka operator+(const Stroka&);    // Оператор конкатенации (возвращает новый объект)
    int operator==(const Stroka&);      // Оператор сравнения
    
    // Методы
    int dlina();
    void vvod();
    void vyvod();
    
    // Дополнительный метод для получения C-строки
    char* getStr() { return str; }
};

#endif