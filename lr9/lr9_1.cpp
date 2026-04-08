#include <iostream>

using namespace std;

class Money
{
    long dollars;
    int cents;

public:
    // конструктор по умолчанию
    Money() {
        dollars = 0;
        cents = 0;
    }
    Money(long d, int c)
    {
        dollars = d;
        cents = c;
    }
    int operator>(const Money &) const;
    friend ostream &operator<<(ostream &, Money &);
};

// перегрузка оператора сравнения, чтобы работал шаблон сортировки
int Money::operator>(const Money &amt) const
{
    return (dollars > amt.dollars) || ((dollars == amt.dollars) && (cents > amt.cents));
}

ostream &operator<<(ostream &os, Money &amt)
{
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}

// шаблон функции сортировки пузырьком массива любого типа данных
template <class T>
void Sort(T array[], size_t size)
{
    int i, j;
    T tmp;
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (array[i] > array[j])
            {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
}

void main(void)
{
    Money mas[] = {Money(19, 10),
                   Money(99, 99),
                   Money(99, 95),
                   Money(19, 95)};

    int masLen = sizeof(mas) / sizeof(mas[0]);

    Sort(mas, masLen);
    for (int i = 0; i < masLen; i++)
    {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
};
