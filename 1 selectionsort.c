#include <stdio.h>

// функция для замены позиций элементов
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            // Ищем минимальный элемент в каждом обороте цикла
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

// выводим массивчик
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Исполнение
int main() {
    int data[] = {-20, 7, -16, 5, 10, -2, 3};
    int data1[] = {9, 5, 7, 3, 6, 4, 2};

    // интересуемся у массива, насколько он длинный?
    int size = sizeof(data) / sizeof(data[0]);
    int size1 = sizeof(data1) / sizeof(data1[0]);

    selectionSort(data, size);
    printf("Sorted array 1 in Acsending Order:\n");
    printArray(data, size);
    selectionSort(data1, size1);
    printf("Sorted array 2 in Acsending Order:\n");
    printArray(data1, size1);
}