#include <stdio.h>
int d = 0;
int m = 0;
// объявляем пузырьки
void bubbleSort(int array[], int size) {

  // цикл бегающий по всем элементам массива
  for (int step = 0; step < size - 1; ++step) {
      
    // цикл сравнивающий элементы массива
    for (int i = 0; i < size - step - 1; ++i) {
      
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
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Исполнение
int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // интересуемся у массива, насколько он длинный?
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  
  printf("Отсортированный массив в порядке возрастания:\n");
  printArray(data, size);
  printf("%d", d);
  printf("%d", m);
}