#include <iostream>

using namespace std;

class Stroka {  
    char* str;  
public:    
    Stroka(char*);
    Stroka() : str(nullptr) {}
    Stroka(const Stroka&);
    ~Stroka();
    Stroka& operator=(const Stroka&);
    Stroka operator+(const Stroka&);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
    friend istream& operator>>(istream&, Stroka&);
    friend ostream& operator<<(ostream&, const Stroka&);
};