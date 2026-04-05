#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string inputFile, outputFile;
    
    cout << "Введите имя входного файла: ";
    cin >> inputFile;
    
    cout << "Введите имя выходного файла: ";
    cin >> outputFile;
    
    ifstream in(inputFile);
    if (!in.is_open()) {
        cerr << "Ошибка: не могу открыть файл " << inputFile << endl;
        return 1;
    }
    
    // Читаем все строки файла
    vector<string> allLines;
    string line;
    while (getline(in, line)) {
        allLines.push_back(line);
    }
    in.close();
    
    // Разбиваем на страницы
    vector<vector<string>> pages;
    vector<string> currentPage;
    
    for (const string& l : allLines) {
        if (l == "\f" || (l.length() == 1 && l[0] == '\f')) {
            if (!currentPage.empty()) {
                pages.push_back(currentPage);
                currentPage.clear();
            }
        } else {
            currentPage.push_back(l);
        }
    }
    if (!currentPage.empty()) {
        pages.push_back(currentPage);
    }
    
    ofstream out(outputFile);
    if (!out.is_open()) {
        cerr << "Ошибка: не могу создать файл " << outputFile << endl;
        return 1;
    }
    
    // Обрабатываем каждую страницу (используем int вместо size_t)
    for (int p = 0; p < (int)pages.size(); p++) {
        vector<string>& page = pages[p];
        
        if (page.empty()) continue;
        
        // Обрабатываем первую строку
        string firstLine = page[0];
        string pageNumber;
        string cleanedFirstLine;
        
        // Ищем номер в формате - число -
        int dash1 = (int)firstLine.find('-');
        if (dash1 != -1) {  // string::npos == -1 для int
            int numStart = dash1 + 1;
            while (numStart < (int)firstLine.length() && isspace(firstLine[numStart])) numStart++;
            
            int numEnd = numStart;
            while (numEnd < (int)firstLine.length() && isdigit(firstLine[numEnd])) numEnd++;
            
            if (numEnd > numStart) {
                int dash2 = (int)firstLine.find('-', numEnd);
                if (dash2 != -1) {
                    pageNumber = firstLine.substr(numStart, numEnd - numStart);
                    
                    // Формируем очищенную строку
                    cleanedFirstLine = firstLine.substr(0, dash1);
                    if (dash2 + 1 < (int)firstLine.length()) {
                        cleanedFirstLine += firstLine.substr(dash2 + 1);
                    }
                    
                    // Убираем лишние пробелы
                    int s = 0;
                    while (s < (int)cleanedFirstLine.length() && isspace(cleanedFirstLine[s])) s++;
                    int e = (int)cleanedFirstLine.length();
                    while (e > s && isspace(cleanedFirstLine[e - 1])) e--;
                    
                    if (s < e) {
                        cleanedFirstLine = cleanedFirstLine.substr(s, e - s);
                    } else {
                        cleanedFirstLine = "";
                    }
                }
            }
        }
        
        // Записываем страницу
        if (!pageNumber.empty()) {
            // Записываем очищенную первую строку (если не пуста)
            if (!cleanedFirstLine.empty()) {
                out << cleanedFirstLine << '\n';
            }
            // Записываем остальные строки (со 2-й по последнюю)
            for (int i = 1; i < (int)page.size(); i++) {
                out << page[i] << '\n';
            }
            // Записываем номер страницы в конце
            out << pageNumber;
        } else {
            // Нет номера - записываем как есть
            for (int i = 0; i < (int)page.size(); i++) {
                out << page[i];
                if (i < (int)page.size() - 1) out << '\n';
            }
        }
        
        // Разделитель между страницами
        if (p < (int)pages.size() - 1) {
            out << "\n\f\n";
        }
    }
    
    out.close();
    cout << "Готово! Результат сохранен в " << outputFile << endl;
    
    return 0;
}