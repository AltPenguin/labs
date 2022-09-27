#include <iostream>
using namespace std;
int main() {
    /* Установим размер массива */
    int n; // Кол-во элементов
    n=7;
    int m = 0;
    int d = 0;
    int a[] = { 9, 5, 7, 3, 6, 4, 2 };
        //Выведем наш массив
        for (int i=0; i < n; i++) {
            cout << a[i] << " ";

        }
        /* Отсортируем массив по убыванию */
    for(int i = 1; i < n; ++i) {

        for (int r = 0; r < n - i; r++) {
            m++;
            if (a[r] < a[r + 1]) {
                d++;
                // Обмен местами
                int b = a[r];
                a[r] = a[r + 1];
                a[r + 1] = b;
            }
        }
    }
    cout << endl;
        /* Выведем отсортированный массив */
    for (int i=0; i < n; i++) {
        cout << a[i] << "";

        
}
cout << "\n" << m << "\n" << d << endl;
    
}
