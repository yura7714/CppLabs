#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// шаблон класса односвязного линейного списка
template <class T>
class Node
{
public:
    T d;
    Node *next;
};
//---------------------------------------------------
template <class T>
Node<T> *first(T d);
template <class T>
void add(Node<T> **pend, T d);
template <class T>
Node<T> *find(Node<T> *const pbeg, int i);
template <class T>
bool remove(Node<T> **pbeg, Node<T> **pend, int key);
template <class T>
Node<T> *insert(Node<T> *const pbeg, Node<T> **pend, int key, T d);
template <class T>
void printList(Node<T> *const ptrBegin);
template <class T>
bool moveItem(int itemId, Node<T> **firstListBegin,
                        Node<T> **firstListEnd,
                        Node<T> **secondListBegin,
                        Node<T> **secondListEnd);
//---------------------------------------------------

class Bus {
public:
    int id;
    string driverName;
    int routeId;
    Bus(int id, string driverName, int routeId) {
        this->id = id;
        this->driverName = driverName;
        this->routeId = routeId;
    }

    bool operator==(const Bus& bus) const {
        return id == bus.id;
    }
};

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Bus* bus1 = new Bus(1, "Васильева Е.С.", 33);
    Bus* bus2 = new Bus(2, "Чусовитин М.А.", 98);
    Bus* bus3 = new Bus(3, "Комиссаренко В.О.", 33);
    Bus* bus4 = new Bus(4, "Максименко В.А.", 10);    

    // Заполнение списка автобусов в парке
    Node<Bus*> *pbegPark = first(bus1); // Формирование первого элемента списка
    Node<Bus*> *pendPark = pbegPark;     // Список заканчивается, едва начавшись
    add(&pendPark, bus2);
    add(&pendPark, bus3);
    add(&pendPark, bus4);

    // Заполнение списка автобусов на линии
    Node<Bus*> *pbegRoute = nullptr;
    Node<Bus*> *pendRoute = pbegRoute;

    int choice = 1;

    do {
        cout << "\nМеню:" << endl;
        cout << "1 - Вывести список автобусов в парке" << endl;
        cout << "2 - Вывести список автобусов на маршруте" << endl;
        cout << "3 - Отправить автобус на маршрут" << endl;
        cout << "4 - Отправить автобус в парк" << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) {
            break;            
        } else if (choice == 1) {
            printList(pbegPark);
        } else if (choice == 2) {
            printList(pbegRoute);
        } else if (choice == 3) {
            // Отправка автобуса на маршрут
            cout << "Введите номер автобуса, который отправить на маршрут: ";
            int busId;
            cin >> busId;

            if (!(moveItem(busId, &pbegPark, &pendPark, &pbegRoute, &pendRoute))) {
                cout << "Автобус с номером " << busId << " отсутствует в парке!" << endl;
            } else {                
                cout << "Автобус с номером " << busId << " вышел на маршрут!" << endl;
            }
        } else if (choice == 4) {
            // Отправка автобуса в парк
            cout << "Введите номер автобуса, который отправить в парк: ";
            int busId;
            cin >> busId;

            if (!(moveItem(busId, &pbegRoute, &pendRoute, &pbegPark, &pendPark))) {
                cout << "Автобус с номером " << busId << " отсутствует на маршруте!" << endl;
            } else {
                cout << "Автобус с номером " << busId << " приехал в парк!" << endl;
            }
        }

    } while (choice != 0);
    
    return 0;
}
//-----------------------------------------------------------------------
// Формирование первого элемента
template <class T>
Node<T> *first(T d)
{
    Node<T> *pv = new Node<T>;
    pv->d = d;
    pv->next = 0;
    return pv;
}
//-------------------------------------------------------
// Добавление в конец списка
template <class T>
void add(Node<T> **pend, T d)
{
    Node<T> *pv = new Node<T>;
    pv->d = d;
    pv->next = 0;
    (*pend)->next = pv;
    *pend = pv;
}
//-------------------------------------------------------
// Поиск элемента по ключу
template <class T>
Node<T> *find(Node<T> *const pbeg, int d)
{
    Node<T> *pv = pbeg;
    while (pv)
    {
        if (pv->d->id == d)
            break;
        pv = pv->next;
    }
    return pv;
}
// Удаление элемента
template <class T>
bool remove(Node<T> **pbeg, Node<T> **pend, int key)
{
    if (Node<T> *pkey = find(*pbeg, key))
    { // 1
        if (pkey == *pbeg)
        { // 2
            *pbeg = (*pbeg)->next;
            if (*pbeg == nullptr) {
                *pend = nullptr;  // Список пуст
            }
        }
        else if (pkey == *pend)
        { // 3
            Node<T> *temp = *pbeg;
            
            // ищем предпоследний элемент
            while ((temp)->next != *pend) {
                temp = temp->next;
            }

            temp->next = 0;
            *pend = temp;
        }
        else
        { // 4
            Node<T> *temp = *pbeg;
            
            // ищем предыдущий элемент
            while ((temp)->next != pkey) {
                temp = temp->next;
            }

            temp->next = pkey->next;
        }
        delete pkey;
        return true; // 5
    }
    return false; // 6
}
// //------------------------------------------------------------------------------------
// Вставка элемента
template <class T>
Node<T> *insert(Node<T> *const pbeg, Node<T> **pend, int key, T d)
{
    if (Node<T> *pkey = find(pbeg, key))
    {
        Node<T> *pv = new Node<T>;
        pv->d = d;
        // 1 - установление связи нового узла с последующим:
        pv->next = pkey->next;
        // 3 - установление связи предыдущего узла с новым:
        pkey->next = pv;
        // 4 - установление связи последующего узла с новым:
        // Обновление указателя на конец списка,
        // если узел вставляется в конец:
        if (pkey == *pend)
            *pend = pv;
        return pv;
    }
    return 0;
}

// вывод списка
template <class T>
void printList(Node<T>* const ptrBegin) {
    if (ptrBegin == nullptr) {
        cout << "Автобусов в этом месте нет!" << endl;
        return;
    }

    Node<T> *pv = ptrBegin;
    cout << left << setw(20) << "Номер автобуса" << setw(30) << "Водитель" << setw(10) << "Маршрут" << endl;
    while (pv)
    { // вывод списка на экран
        cout << left << setw(20) << pv->d->id << setw(30) << pv->d->driverName << setw(10) << pv->d->routeId << endl;
        pv = pv->next;
    }
}

// переместить элемент с id = itemId из firstList в secondList
template <class T>
bool moveItem(int itemId, Node<T> **firstListBegin,
                        Node<T> **firstListEnd,
                        Node<T> **secondListBegin,
                        Node<T> **secondListEnd) {
    Node<T> *foundItem = find(*firstListBegin, itemId);

    if (foundItem == nullptr) {
        return false;
    } 

    // если ещё ни одного элемента во втором списке
    if (*secondListBegin == nullptr) {
        *secondListBegin = first(foundItem->d);
        *secondListEnd = *secondListBegin;
    } else {
        add(secondListEnd, foundItem->d);
    }
    
    remove(firstListBegin, firstListEnd, itemId);

    return true;
}