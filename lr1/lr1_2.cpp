#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)
#define PR_double(x) printf("x=%u, *x=%e, &x=%u\n", x, *x, &x)
#include <stdio.h>

void main(void)
{
    // Указатели на целые числа
    printf("Arrays of int:\n");
    int mas[] = {100, 200, 300};
    int *ptr1, *ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2 - ptr1 = %u\n", ptr2 - ptr1);

    // Указатели на булевы переменные
    printf("Booleans:\n");
    bool falseCond = false, trueCond = true;
    bool *ptr3 = &falseCond;
    bool *ptr4 = &trueCond;
    PR(ptr3);
    PR(ptr4);

    printf("ptr3 == ptr4 = %u\n", ptr3 == ptr4);

    // Указатели на числа с плавающей точкой
    printf("Arrays of double:\n");
    double arr[] = {7.714, 1.};

    double *ptr5, *ptr6;
    ptr5 = arr;
    ptr6 = &arr[1];
    PR_double(ptr5);
    ptr5++;
    PR_double(ptr5);
    PR_double(ptr6);
    ++ptr6;
    printf("ptr6 - ptr5 = %u\n", ptr6 - ptr5);
}