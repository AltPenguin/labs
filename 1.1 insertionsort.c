#include <stdio.h>
int d;
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
  int data[] = {6, 1, 5, 0, 8, 2, 3, 7, 4};
  int size = sizeof(data) / sizeof(data[0]);
  // интересуемся у массива, насколько он длинный?
  insertionSort(data, size);
  printf("Отсортированный массив в порядке возрастания:\n");
  printArray(data, size);
}