class Stroka {
    char* str;
public:
    Stroka(char*);
    Stroka() {}
    Stroka(const Stroka&);
    ~Stroka();
    Stroka& operator=(const Stroka&);
    Stroka operator+(const Stroka&);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};