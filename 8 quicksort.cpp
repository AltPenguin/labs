#include <iostream>
using namespace std;

// функция подмены элементов
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// функция вывода массива
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// функция переупорядочивания массива (найти точку раздела)
int partition(int array[], int low, int high) {
    
  //выберите крайний правый элемент в качестве опорного
  int pivot = array[high];
  
  //указатель на старший элемент
  int i = (low - 1);

  // пройтись по каждому элементу массива, сравнить их со сводной точкой
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // если найден элемент, меньший, чем точка поворота, поменяйте его местами с старшим элементом, на который указывает i
      i++;
      
      // поменять местами элемент в i с элементом в j
      swap(&array[i], &array[j]);
    }
  }
  
  // поменять местами точку опоры со старшим элементом в точке i
  swap(&array[i + 1], &array[high]);
  
  // возвращаем точку раздела
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // ищем опорный элемент такой, что
    // элементы, меньшие, чем точка поворота, находятся слева от точки поворота
    // элементы, меньшие, чем точка поворота, находятся справа от точки поворота
    int pi = partition(array, low, high);

    // рекурсивный вызов слева от точки поворота
    quickSort(array, low, pi - 1);

    // рекурсивный вызов справа от точки поворота
    quickSort(array, pi + 1, high);
  }
}

// Исполнение
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Несортированный массив: \n";
  printArray(data, n);
  
  // Выполнение квиксорта
  quickSort(data, 0, n - 1);
  
  cout << "Отсортированный массив в порядке возрастания: \n";
  printArray(data, n);
}