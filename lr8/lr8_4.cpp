#include <iostream>
#include <fstream>

using namespace std;

const char fname[] = "_NewFile";

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Проверяем существование файла перед созданием
    ifstream test(fname);

    // Изменяем состояние потока - устанавливаем флаг failbit
    test.clear(test.rdstate() | ios::failbit);

    if (test.rdstate() & ios::failbit) {
        cout << "Установлен флаг failbit";
    }

    // Из-за установленного флага failbit if (test) == false
    if (test)
    {
        cout << "Ошибочная ситуация! Файл "
             << fname
             << " уже существует."
             << endl;
        return 0;
    }
    test.close();

    // Создаем новый файл
    ofstream ofs(fname);

    ofs << "Эта строка записывается "
        << "в новый файл";
    ofs.close(); // Закрываем файл
    fstream fs;  // Определяем новый объект
    // Открываем файл и устанавливаем на EOF
    fs.open(fname, ios::out | ios::app);
    fs << "Сейчас к ней сделано добавление";
    fs.close(); // Закрываем файл

    // Открываем файл как входной
    fstream ifs;
    ifs.open(fname, ios::in);

    if (ifs)
    {
        cout << "В старом файле содержится"
             << "..." << endl;
        char Line[80];
        ifs.getline(Line, sizeof(Line));
        cout << Line;
    }
    else
    {
        cout << "Ошибочная ситуация "
             << "при повторном открытии "
             << fname
             << endl;
    }

    return 0;
}