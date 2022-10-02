#include <stdio.h>
#define SIZE 10000
int d = 0;
int m = 0;
// Печатаем массивчик
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        m++;
        // Сравниваем каждый элемент со всеми элементами слева, перемещаем пока не добьемся условия
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            d++;
            --j;
        }
        array[j + 1] = key;
    }
}

// Исполнение
int main() {
    int data[SIZE];
    int size = sizeof(data) / sizeof(data[0]);
    // интересуемся у массива, насколько он длинный?
    insertionSort(data, size);
    printf("Output:\n");
    printArray(data, size);
    printf("%d \n",m+d);

}