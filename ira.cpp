#include<stdlib.h>
#include <time.h>
#include <iomanip>
#include <iostream>
 
void print(int, int); 
void nya(int, int); 
using namespace std;
int main()
{
    srand(time(NULL));
    const int size = 20;
    int array[size];
    for (int i=0;i<size;i++)
        array[i]=1+rand()%30;
        cout << " Созданный массив" << "\n\n";
        print(array, size);
        nya (array, size);
        cout << " Отсортированный массив" <<"\n\n";
        print(array, size);
        return 0;
}
void print(int arr, int sizeOfArray) 
{
    for (int k = 0; k < sizeOfArray; k++)
    cout << arr[k]<<" ";
    cout <<"\n\n";
}
void nya(int arr, int sizeOfArray)
{
    int countcompare=0; 
    int m = 0;
        for(int i = 1; i < sizeOfArray; i++) 
            for(int j = 0; j < sizeOfArray - 1;j++) 
    {
            countcompare++;
                if (arr[j ] < arr[j +1])
        {
                     m++;
                     int tmp = arr[j + 1];
                     arr[j + 1] = arr[j];
                     arr[j] = tmp;
        }
    }
    cout<<" Подсчёт сравнений:\n"<<countcompare <<"\n";
    cout<<" Подсчёт перестановок:\n"<< m <<"\n";
    cout<<" Зависимость сложности алгоритма:\n"<<countcompare + m <<"\n";
    cout <<"\n";
}