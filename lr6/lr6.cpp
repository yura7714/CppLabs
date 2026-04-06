#include "Stroka.h"
#include <iostream>

using namespace std;

void main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Stroka s1("qwert"), s3, s4(s1), s5;
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    cout << endl;
    s5 = s1 + s3 + s4;
    cout << "длина s5 = " << s5.dlina() << endl;
    s5.vyvod();
    cout << endl;
    if (s1 == s5)
        cout << "строки s1 и s5 равны" << endl;
    else
        if (s1 == s4)
            cout << "строки s1 и s4 равны" << endl;
}