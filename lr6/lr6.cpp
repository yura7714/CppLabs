#include "Stroka.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "========== Тестирование класса Stroka ==========" << endl << endl;
    
    // 1. Проверка конструкторов
    cout << "1. Создание объектов:" << endl;
    Stroka s1("qwert");        // Конструктор из C-строки
    Stroka s2;                  // Конструктор по умолчанию
    Stroka s3(100);             // НОВЫЙ конструктор с размером
    Stroka s4(s1);              // Конструктор копирования
    
    cout << endl;
    
    // 2. Проверка ввода/вывода
    cout << "2. Проверка ввода/вывода:" << endl;
    s2.vvod();                  // Ввод строки
    cout << "Вы ввели: ";
    s2.vyvod();
    cout << endl << endl;
    
    // 3. Проверка оператора присваивания
    cout << "3. Проверка оператора присваивания:" << endl;
    Stroka s5;
    s5 = s1;                    // Оператор присваивания
    cout << "s5 = ";
    s5.vyvod();
    cout << endl << endl;
    
    // 4. Проверка оператора конкатенации
    cout << "4. Проверка оператора конкатенации:" << endl;
    Stroka s6 = s1 + s2;        // Оператор +
    cout << "s1 + s2 = ";
    s6.vyvod();
    cout << endl << endl;
    
    // 5. Проверка длины строки
    cout << "5. Проверка длины строки:" << endl;
    cout << "Длина s1 = " << s1.dlina() << endl;
    cout << "Длина s2 = " << s2.dlina() << endl;
    cout << "Длина s6 = " << s6.dlina() << endl << endl;
    
    // 6. Проверка сравнения строк
    cout << "6. Проверка сравнения строк:" << endl;
    Stroka s7("qwert");
    if (s1 == s7) {
        cout << "s1 и s7 равны" << endl;
    } else {
        cout << "s1 и s7 не равны" << endl;
    }
    
    if (s1 == s2) {
        cout << "s1 и s2 равны" << endl;
    } else {
        cout << "s1 и s2 не равны" << endl;
    }
    cout << endl;
    
    // 7. Проверка цепочки операций (как в задании)
    cout << "7. Проверка цепочки операций (s1 + s3 + s4):" << endl;
    Stroka s8;
    s8 = s1 + s3 + s4;
    cout << "Результат: ";
    s8.vyvod();
    cout << endl;
    cout << "Длина результата: " << s8.dlina() << endl << endl;
    
    cout << "========== Конец программы ==========" << endl;
    cout << "Деструкторы вызовутся автоматически" << endl;
    
    return 0;
}