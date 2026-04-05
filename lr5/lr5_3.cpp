#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// функция, которая шифрует контент файла inputFileName по ключу key и выводит его в outputFileName
bool processFile(const string& inputFileName, 
                 const string& outputFileName, 
                 const string& key) {
    
    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть входной файл: " << inputFileName << endl;
        return false;
    }
    
    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Ошибка: Не удалось создать выходной файл: " << outputFileName << endl;
        inputFile.close();
        return false;
    }
    
    if (key.empty()) {
        cerr << "Ошибка: Ключ не может быть пустым" << endl;
        inputFile.close();
        outputFile.close();
        return false;
    }
    
    char c;
    int keyLength = key.length();
    int keyIndex = 0;
    
    while (inputFile.get(c)) {
        char encodedChar = c ^ key[keyIndex];
        outputFile.put(encodedChar);
        keyIndex = (keyIndex + 1) % keyLength;
    }
    
    inputFile.close();
    outputFile.close();
    
    return true;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string inputFileName, outputFileName, key;
    
    cout << "Введите входной файл, выходной файл и ключ через пробел: " << endl;
    cin >> inputFileName >> outputFileName >> key;
    
    cout << "\nВходной файл: " << inputFileName << endl;
    cout << "Выходной файл: " << outputFileName << endl;
    cout << "Ключ: " << key << endl;
    cout << "Обработка файла..." << endl;
    
    if (processFile(inputFileName, outputFileName, key)) {
        cout << "Успех! Файл обработан." << endl;
        return 0;
    } else {
        cerr << "Ошибка: Не удалось обработать файл" << endl;
        return 1;
    }
}