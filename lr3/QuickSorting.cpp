#include <iostream>
using namespace std;

// Функция для обмена элементов
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция разбиения (partition) - выбирает опорный элемент и размещает элементы
// меньше опорного слева, а больше - справа
int partition(int arr[], int low, int high, bool isAscendingOrder) {
    // Выбираем опорный элемент (в данном случае - последний элемент)
    int pivot = arr[high];
    
    // Индекс для элемента, который меньше опорного
    int i = (low - 1);
    
    // Проходим по всем элементам от low до high-1
    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (isAscendingOrder && arr[j] <= pivot || !isAscendingOrder && arr[j] > pivot) {
            i++; // Увеличиваем индекс меньших элементов
            swap(arr[i], arr[j]); // Меняем местами
        }
    }
    
    // Ставим опорный элемент на правильное место
    swap(arr[i + 1], arr[high]);
    return (i + 1); // Возвращаем позицию опорного элемента
}

// Альтернативная версия функции сортировки чет/нечет с использованием быстрой сортировки
int partitionEvenOdd(int arr[], int low, int high, bool even) {
    if (even) {
        // Для четных - по возрастанию
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    } else {
        // Для нечетных - по убыванию
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] >= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
}

// Основная функция быстрой сортировки
void quickSort(int arr[], int low, int high, bool isAscendingOrder = true) {
    if (low < high) {
        // Получаем индекс опорного элемента после разбиения
        int pi = partition(arr, low, high, isAscendingOrder);
        
        // Рекурсивно сортируем элементы до и после опорного
        quickSort(arr, low, pi - 1, isAscendingOrder);  // Сортируем левую часть
        quickSort(arr, pi + 1, high, isAscendingOrder); // Сортируем правую часть
    }
}

void quickSortEvenOdd(int arr[], int low, int high, bool even) {
    if (low < high) {
        int pi = partitionEvenOdd(arr, low, high, even);
        quickSortEvenOdd(arr, low, pi - 1, even);
        quickSortEvenOdd(arr, pi + 1, high, even);
    }
}

// Функция быстрой сортировки БЕЗ опорного элемента (использует разделение на две части)
void quickSortWithoutPivot(int arr[], int low, int high) {
    if (low < high) {
        // Выбираем средний элемент как разделитель
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];
        
        int i = low;
        int j = high;
        
        // Разделяем массив на две части: элементы меньше pivot и больше pivot
        while (i <= j) {
            // Ищем элемент, который должен быть справа от pivot
            while (arr[i] < pivot) {
                i++;
            }
            // Ищем элемент, который должен быть слева от pivot
            while (arr[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
        // Рекурсивно сортируем левую и правую части
        if (low < j) {
            quickSortWithoutPivot(arr, low, j);
        }
        if (i < high) {
            quickSortWithoutPivot(arr, i, high);
        }
    }
}

void sortEvenOddAdvanced(int arr[], int n) {
    // Сначала разделяем массив на четные и нечетные числа
    int* temp = new int[n];
    int evenIndex = 0;
    int oddIndex = n - 1;
    
    // Копируем исходный массив
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    // Разделяем: четные в начало, нечетные в конец
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++) {
        if (temp[i] % 2 == 0) {
            arr[left++] = temp[i];
        } else {
            arr[right--] = temp[i];
        }
    }
    
    // Сортируем четные (первые evenCount элементов) по возрастанию
    int evenCount = left;
    if (evenCount > 1) {
        quickSortEvenOdd(arr, 0, evenCount - 1, true);
    }
    
    // Сортируем нечетные (последние oddCount элементов) по убыванию
    int oddCount = n - evenCount;
    if (oddCount > 1) {
        quickSortEvenOdd(arr, evenCount, n - 1, false);
    }
    
    delete[] temp;
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Тестирование сортировки с опорным элементом
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "=== Сортировка c опорным элементом ===" << endl;
    cout << "Исходный массив: ";
    printArray(arr1, n1);
    
    quickSort(arr1, 0, n1 - 1);
    
    cout << "Отсортированный массив: ";
    printArray(arr1, n1);
    
    cout << endl;
    
    // Тестирование сортировки без опорного элемента
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "=== Сортировка без опорного элемента ===" << endl;
    cout << "Исходный массив: ";
    printArray(arr2, n2);
    
    quickSortWithoutPivot(arr2, 0, n2 - 1);
    
    cout << "Отсортированный массив: ";
    printArray(arr2, n2);

    cout << "=== Сортировка с опорным элементом (четные по возрастанию, нечетные по убыванию) ===" << endl;
    int arr3[] = {10, 7, 8, 9, 1, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Исходный массив: ";
    printArray(arr3, n3);

    sortEvenOddAdvanced(arr3, n3);

    cout << "Отсортированный массив: ";
    printArray(arr3, n3);


    int ix_n1 = 2;
    int ix_n2 = 7;

    cout << "=== Сортировка с опорным элементом по возрастанию с индексом от " << ix_n1 << " до " << ix_n2 << " ===" << endl;
    int arr4[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Исходный массив: ";
    printArray(arr4, n4);

    quickSort(arr4, ix_n1, ix_n2);

    cout << "Отсортированный массив: ";
    printArray(arr4, n4);

    cout << "=== Сортировка с опорным элементом по убыванию с индексом от " << ix_n1 << " до " << ix_n2 << " ===" << endl;
    int arr5[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "Исходный массив: ";
    printArray(arr5, n5);

    quickSort(arr5, ix_n1, ix_n2, false);

    cout << "Отсортированный массив: ";
    printArray(arr5, n5);

    return 0;
}