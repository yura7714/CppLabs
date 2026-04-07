#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char inputFileName[50];
    char outputFileName[50];
    char key[50];
    char ch;
    int keyIndex = 0, keyLength = 0;
    
    cout << "Введите входной файл, выходной файл и ключ через пробел: " << endl;
    cin >> inputFileName >> outputFileName >> key;
    
    cout << "\nВходной файл: " << inputFileName << endl;
    cout << "Выходной файл: " << outputFileName << endl;
    cout << "Ключ: " << key << endl;

    char* ptr = key;
    while (*ptr != '\0') {
        keyLength++;
        ptr++;
    }

    cout << "Обработка файла..." << endl;

    FILE* in;
    FILE *out;

    if((in=fopen(inputFileName, "r")) == NULL) {
        cout << "Файл " << inputFileName << " не открыт!" << endl;
        return 1;
    }

    if ((out = fopen(outputFileName, "w")) == NULL) {
        cout << "Файл " << outputFileName << " не открыт!" << endl;
        return 1;
    }

    while (!feof(in)) {
        ch = getc(in);

        char encodedChar = ch ^ key[keyIndex];
        fputc(encodedChar, out);
        keyIndex = (keyIndex + 1) % keyLength;
    }

    cout << "Файл обработан" << endl;
}