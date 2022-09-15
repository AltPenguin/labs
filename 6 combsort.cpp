#include<bits/stdc++.h>
using namespace std;
 
// Ищем зазор между элементами
int getNextGap(int gap)
{
    // Усадочный зазор по коэффициенту усадки
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 
// Функция для сортировки [0..n-1] с использованием гребенчатой сортировки
void combSort(int a[], int n)
{
    // Инициализируем зазор
    int gap = n;
 
    // Инициализация заменена как истина, чтобы убедиться, что цикл работает
    bool swapped = true;
 
    // Продолжаем бегать, пока зазор больше 1, а последняя итерация вызвала замену
    while (gap != 1 || swapped == true)
    {
        // Ищем следующий зазор
        gap = getNextGap(gap);
 
        // Инициализируем обмен как ложный, чтобы мы могли проверить, произошел ли обмен или нет
        swapped = false;
 
        // Сравниваем элемент с текущим зазором
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}
 
// Исполнение
int main()
{
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);
 
    combSort(a, n);
 
    printf("Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
 
    return 0;
}