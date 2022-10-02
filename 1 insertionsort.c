#include <stdio.h>
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

        // Сравниваем каждый элемент со всеми элементами слева, перемещаем пока не добьемся условия
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Исполнение
int main() {
    int data[] = {-20, 7, -16, 5, 10, -2, 3};
    int data1[] = {9, 5, 7, 3, 6, 4, 2};

    // интересуемся у массива, насколько он длинный?
    int size = sizeof(data) / sizeof(data[0]);
    int size1 = sizeof(data1) / sizeof(data1[0]);

    insertionSort(data, size);
    printf("Sorted array 1 in Acsending Order:\n");
    printArray(data, size);
    insertionSort(data1, size1);
    printf("Sorted array 2 in Acsending Order:\n");
    printArray(data1, size1);
}