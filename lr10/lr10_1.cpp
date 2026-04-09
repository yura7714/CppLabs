#include <iostream>

using namespace std;

// Односвязный линейный список

struct Node
{
    int d;
    Node *next;
};
//---------------------------------------------------
Node *first(int d);
void add(Node **pend, int d);
Node *find(Node *const pbeg, int i);
bool remove(Node **pbeg, Node **pend, int key);
Node *insert(Node *const pbeg, Node **pend, int key, int d);
//---------------------------------------------------
int main()
{
    Node *pbeg = first(1); // Формирование первого элемента списка
    Node *pend = pbeg;     // Список заканчивается, едва начавшись
    // Добавление в конец списка четырех элементов 2. 3. 4.	и 5:
    for (int i = 2; i < 6; i++)
        add(&pend, i);
    // Вставка элемента 200 после элемента 2:
    insert(pbeg, &pend, 2, 200);
    // Удаление элемента 5:
    if (!remove(&pbeg, &pend, 5))
        cout << "не найден";
    Node *pv = pbeg;
    while (pv)
    { // вывод списка на экран
        cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}
//-----------------------------------------------------------------------
// Формирование первого элемента
Node *first(int d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    return pv;
}
//-------------------------------------------------------
// Добавление в конец списка
void add(Node **pend, int d)
{
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    (*pend)->next = pv;
    *pend = pv;
}
//-------------------------------------------------------
// Поиск элемента по ключу
Node *find(Node *const pbeg, int d)
{
    Node *pv = pbeg;
    while (pv)
    {
        if (pv->d == d)
            break;
        pv = pv->next;
    }
    return pv;
}
// Удаление элемента
bool remove(Node **pbeg, Node **pend, int key)
{
    if (Node *pkey = find(*pbeg, key))
    { // 1
        if (pkey == *pbeg)
        { // 2
            *pbeg = (*pbeg)->next;
        }
        else if (pkey == *pend)
        { // 3
            Node *temp = *pbeg;
            
            // ищем предпоследний элемент
            while ((temp)->next != *pend) {
                temp = temp->next;
            }

            temp->next = 0;
            *pend = temp;
        }
        else
        { // 4
            Node *temp = *pbeg;
            
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
//------------------------------------------------------------------------------------
// Вставка элемента
Node *insert(Node *const pbeg, Node **pend, int key, int d)
{
    if (Node *pkey = find(pbeg, key))
    {
        Node *pv = new Node;
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
