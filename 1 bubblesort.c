#include <stdio.h>
// объявляем пузырьки
void bubbleSort(int array[], int size) {

    // цикл бегающий по всем элементам массива
    for (int step = 0; step < size - 1; ++step) {

        // цикл сравнивающий элементы массива
        for (int i = 0; i < size - step - 1; ++i) {
            
            // сравниваем двух соседей
            if (array[i] > array[i + 1]) {

                // замена при соблюдении условий
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
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

    bubbleSort(data, size);
    printf("Sorted array 1 in Acsending Order:\n");
    printArray(data, size);
    bubbleSort(data1, size1);
    printf("Sorted array 2 in Acsending Order:\n");
    printArray(data1, size1);

}
