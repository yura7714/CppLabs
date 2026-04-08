#include <iostream>

using namespace std;

template <class T>
class Tstack
{
protected:
    int numItem;
    T *item;

public:
    Tstack(size_t size = 10)
    {
        numItem = 0;
        item = new T[size];
    }
    ~Tstack()
    {
        delete[] item;
    }
    void push(T t);
    T pop();
    int size();
};
template <class T>
void Tstack<T>::push(T t)
{
    item[numItem++] = t;
}
template <class T>
T Tstack<T>::pop()
{
    return item[--numItem];
}
template <class T>
int Tstack<T>::size() {
    return numItem;
}

int main() {
    Tstack<int> railwayIn;
    Tstack<int> railwaySiding;
    Tstack<int> railwayOut;
    
    railwayIn.push(3);
    railwayIn.push(5);
    railwayIn.push(1);
    railwayIn.push(10);
    railwayIn.push(15);
    railwayIn.push(8);
    railwayIn.push(11);
    railwayIn.push(4);
    railwayIn.push(7);

    int currentWagon, lastOutWagon;

    // пока есть вагоны на входе или в тупике
    while (railwayIn.size() > 0 || railwaySiding.size() > 0) {
        if (railwayIn.size() > 0) {
            currentWagon = railwayIn.pop();
        } else if (railwaySiding.size() > 0) {
            currentWagon = railwaySiding.pop();
        }

        // текущий вагон всегда уходит на выход, на следующих итерациях может быть выведен в тупик
        if (railwayOut.size() == 0) {
            railwayOut.push(currentWagon);
        } else {
            lastOutWagon = railwayOut.pop();
            while (currentWagon < lastOutWagon && railwayOut.size() > 0) {
                railwaySiding.push(lastOutWagon);
                lastOutWagon = railwayOut.pop();
            }

            railwaySiding.push(lastOutWagon);

            // сравниваем вагон на входе и первый вагон в тупике
            if (currentWagon < lastOutWagon) {
                railwayOut.push(currentWagon);
                railwayOut.push(railwaySiding.pop());
            } else {
                railwayOut.push(railwaySiding.pop());
                railwayOut.push(currentWagon);
            }            
        }
    }

    while (railwayOut.size() > 0) {
        cout << railwayOut.pop() << endl;
    }

    return 0;
}