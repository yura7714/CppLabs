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
};