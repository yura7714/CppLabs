#include <iostream>
#include <cstring>  
#include <clocale>  
#include <cstdlib>  

using namespace std;

int dlina1(char *);
int dlina2(char *);
int dlina3(char *);
void kopir(char *, char *);
int sravn(char *, char *);
char* konkat(char *, char *);

// Дополнительная функция для вывода массива строк
void printStringArray(char** arr, int size, const char* arrayName) {
    cout << arrayName << ": ";
    for (int i = 0; i < size; i++) {
        cout << "\"" << arr[i] << "\"";
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
   
    const int STRING_COUNT = 5;  // количество строк в массиве
    const int MAX_STRING_LEN = 100;  // максимальная длина каждой строки
    
    // Выделение памяти для массива указателей на строки
    char** strings = (char**)calloc(STRING_COUNT, sizeof(char*));
    
    // Выделение памяти для каждой строки и инициализация
    strings[0] = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(strings[0], "Hello");
    
    strings[1] = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(strings[1], "World");
    
    strings[2] = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(strings[2], "C++ Programming");
    
    strings[3] = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(strings[3], "Dynamic");
    
    strings[4] = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(strings[4], "Memory");
    
    // Проверка успешности выделения памяти
    bool memoryError = false;
    for (int i = 0; i < STRING_COUNT; i++) {
        if (strings[i] == NULL) {
            cout << "Ошибка выделения памяти для строки " << i << endl;
            memoryError = true;
        }
    }
    if (memoryError) return 1;
    
    // Вывод исходного массива строк
    cout << "Исходный массив строк:" << endl;
    printStringArray(strings, STRING_COUNT, "strings");
    
    cout << "1. Определение длины строк" << endl;
    for (int i = 0; i < STRING_COUNT; i++) {
        cout << "Строка " << i << " \"" << strings[i] << "\":" << endl;
        cout << "  dlina1 (перебором): " << dlina1(strings[i]) << endl;
        cout << "  dlina2 (разница указателей): " << dlina2(strings[i]) << endl;
        cout << "  dlina3 (рекурсия): " << dlina3(strings[i]) << endl;
    }
    cout << endl;
    
    cout << "2. Копирование строк" << endl;
    
    // Создаем копию первой строки
    char* copyStr = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(copyStr, strings[0]);
    
    cout << "До копирования: copyStr = \"" << copyStr << "\"" << endl;
    kopir(copyStr, strings[2]);  // копируем strings[2] в copyStr
    cout << "После копирования strings[2] в copyStr: \"" << copyStr << "\"" << endl;
    
    // Копирование между элементами массива
    char* tempStr = (char*)calloc(MAX_STRING_LEN, sizeof(char));
    strcpy(tempStr, strings[3]);
    kopir(strings[3], strings[4]);
    cout << "После копирования strings[4] в strings[3]: strings[3] = \"" << strings[3] << "\"" << endl;
    kopir(strings[4], tempStr);
    cout << "После восстановления strings[4] из tempStr: strings[4] = \"" << strings[4] << "\"" << endl;
    
    free(tempStr);
    cout << endl;
    
    cout << "3. Сравнение строк" << endl;
    for (int i = 0; i < STRING_COUNT; i++) {
        for (int j = i + 1; j < STRING_COUNT; j++) {
            int result = sravn(strings[i], strings[j]);
            cout << "sravn(\"" << strings[i] << "\", \"" << strings[j] << "\") = ";
            if (result == 0) {
                cout << "0 (строки равны)" << endl;
            } else if (result > 0) {
                cout << "1 (\"" << strings[i] << "\" > \"" << strings[j] << "\")" << endl;
            } else {
                cout << "-1 (\"" << strings[i] << "\" < \"" << strings[j] << "\")" << endl;
            }
        }
    }
    cout << endl;
    
    cout << "4. Конкатенация строк" << endl;
    
    // Конкатенация различных пар строк из массива
    char* concat1 = konkat(strings[0], strings[1]);
    cout << "konkat(\"" << strings[0] << "\", \"" << strings[1] << "\") = \"" << concat1 << "\"" << endl;
    free(concat1);
    
    char* concat2 = konkat(strings[2], strings[3]);
    cout << "konkat(\"" << strings[2] << "\", \"" << strings[3] << "\") = \"" << concat2 << "\"" << endl;
    free(concat2);
    
    char* concat3 = konkat(strings[4], strings[0]);
    cout << "konkat(\"" << strings[4] << "\", \"" << strings[0] << "\") = \"" << concat3 << "\"" << endl;
    free(concat3);
    
    // Конкатенация трех строк
    char* tempConcat = konkat(strings[0], strings[1]);
    char* concat4 = konkat(tempConcat, strings[2]);
    cout << "konkat(konkat(\"" << strings[0] << "\", \"" << strings[1] << "\"), \"" << strings[2] << "\") = \"" << concat4 << "\"" << endl;
    free(tempConcat);
    free(concat4);
    
    cout << endl;
    
    free(copyStr);
    
    // Освобождаем каждую строку в массиве
    for (int i = 0; i < STRING_COUNT; i++) {
        free(strings[i]);
    }
    // Освобождаем массив указателей
    free(strings);
    
    return 0;
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
// возвращает 1, если str1 > str2
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
// возвращает новую строку в динамической памяти
char* konkat(char* str1, char* str2) {
    const int totalLen = dlina1(str1) + dlina1(str2) + 1;
    char* concatStr = (char*)calloc(totalLen, sizeof(char));
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