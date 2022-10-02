#include <stdio.h>
#define SIZE (Указываем число от 100 до 10000)
int m = 0;
int d = 0;

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
            m++;
            if (array[i] < array[min_idx])
                min_idx = i;
                d++;
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
    int data[SIZE];
    // интересуемся у массива, насколько он длинный?
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Output:\n");
    printArray(data, size);
    printf("%d \n",m+d);
}