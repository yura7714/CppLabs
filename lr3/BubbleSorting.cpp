#include <iostream>
using namespace std;

// Функция для сортировки пузырьком
void bubbleSort(int arr[], int n) {
    // Внешний цикл: количество проходов по массиву
    // После каждого прохода наибольший элемент "всплывает" в конец
    for (int i = 0; i < n - 1; i++) {
        
        // Внутренний цикл: сравнение соседних элементов
        // n-i-1 - потому что последние i элементов уже на своих местах
        for (int j = 0; j < n - i - 1; j++) {
            
            // Если текущий элемент больше следующего, меняем их местами
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Главная функция для демонстрации работы алгоритма
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Пример массива для сортировки
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Исходный массив: ";
    printArray(arr, n);
    
    // Вызываем функцию сортировки
    bubbleSort(arr, n);
    
    cout << "Отсортированный массив: ";
    printArray(arr, n);
    
    return 0;
}