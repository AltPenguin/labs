#include <iostream>
using namespace std;

// Объеденяем два подмассива L и M в массив
void merge(int arr[], int p, int q, int r) {
  
  // Создаём L ← A[p..q] и M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Поддерживаем текущий индекс подмассивов и основного массива
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  /* Пока мы не достигнем ни одного из концов L или M, 
  выбираем элементы L и M большего размера и помещаем 
  их в правильную позицию в A[p..r]*/
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  /* Когда у нас заканчиваются элементы либо в L, либо в M,
   берем оставшиеся элементы и вставляем A[p..r]   */
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Разделяем массив на два подмассива, сортируем их и объединияем.
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m — точка, в которой массив делится на два подмассива
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Объединяем отсортированные подмассивы
    merge(arr, l, m, r);
  }
}

// Выводим массив
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Исполнение
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Отсортированный массив: \n";
  printArray(arr, size);
  return 0;
}