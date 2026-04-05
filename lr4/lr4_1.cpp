#include <iostream>

using namespace std;

void main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char str1[] = "qwerty", str2[] = "1234567890";
    int dlina1(char *);
    int dlina2(char *);
    int dlina3(char *);
    void kopir(char *, char *);
    int sravn(char *, char *);
    char* konkat(char *, char *);

    cout << "длина str1=" << dlina1(str1) << ", str2=";
    cout << dlina1(str2) << endl;
    cout << "длина str1=" << dlina2(str1) << ", str2=";
    cout << dlina2(str2) << endl;
    cout << "длина str1=" << dlina3(str1) << ", str2=";
    cout << dlina3(str2) << endl;
    kopir(str1, str2);
    cout << "результат копирования:str1=" << str1;
    cout << ", str2=" << str2 << endl;

    int comparer = sravn(str1, str2);
    if (comparer == 0)
    {
        cout << "Строки " << str1 << " и " << str2 << " равны" << endl;
    }
    else if (comparer > 0)
    {
        cout << "Строка " << str1 << " больше строки " << str2 << endl;
    }
    else
    {
        cout << "Строка " << str1 << " меньше строки " << str2 << endl;
    }

    char* concatRes = konkat(str1, str2);
    cout << "результат сцепления:str1=" << str1;
    cout << ", str2=" << str2 << endl;
    cout << "результат: " << concatRes << endl;
}

// длина строки перебором всех символов
int dlina1(char *str)
{
    int counter = 0;

    while (*str != '\0')
    {
        counter++;
        str++;
    }

    return counter;
}

// длина строки через разницу указателей
int dlina2(char *str)
{
    char *firstSymbolPtr = str;

    while (*str != '\0')
    {
        str++;
    }

    return str - firstSymbolPtr;
}

// длина строки через рекурсию
int dlina3(char *str)
{
    if (*str == '\0')
    {
        return 0;
    }

    return 1 + dlina3(++str);
}

// копирование строки
void kopir(char *strDest, char *strSource)
{
    while (*strSource != '\0' && *strDest != '\0')
    {
        *strDest = *strSource;
        strSource++;
        strDest++;
    }

    *strDest = '\0';
}

// сравнение строк
// вовзращает 1, если str1 > str2
// возвращает 0, если str1 == str2
// возвращает -1, если str1 < str2
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

// конкатенация строк
// возвращает новую строку
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