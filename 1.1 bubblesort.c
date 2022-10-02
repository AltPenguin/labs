#include <stdio.h>
#define SIZE 1000
int d = 0;
int m = 0;
// объявляем пузырьки
void bubbleSort(int array[SIZE], int size) {

    // цикл бегающий по всем элементам массива
    for (int step = 0; step < SIZE - 1; ++step) {

        // цикл сравнивающий элементы массива
        for (int i = 0; i < SIZE - step - 1; ++i) {

            m = m + 1;
            // сравниваем двух соседей
            if (array[i] > array[i + 1]) {

                // замена при соблюдении условий
                d = d+1;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// выводим массивчик
void printArray(int array[SIZE], int size) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Исполнение
int main() {
    int data[] = {};

    // интересуемся у массива, насколько он длинный?
    int size = SIZE;

    bubbleSort(data, size);

    printf("Output:\n");
    printArray(data, size);
    printf("%d", m);
    printf("\n");
    printf("%d", d);
}