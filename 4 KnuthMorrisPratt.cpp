/*Вариант алгоритма Кнута-Морриса-Пратта для вводных данных на английском языке*/
#include <iostream>
using namespace std;
 
// Функция для реализации алгоритма KMP
void find_substring(string text, string pattern)
{
    int m = text.length();
    
    int n = pattern.length();
 
    // если шаблон это пустая строка
    if (n == 0)
    {
        cout << "Шаблон не найден";
        return;
    }
 
    // если длина текста меньше длины шаблона
    if (m < n)
    {
        cout << "Шаблон не найден";
        return;
    }
 
    // next[i] сохраняет индекс следующего лучшего частичного совпадения
    int next[n + 1];
 
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
 
        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }
 
        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++)
    {
        if (text[i] == pattern[j])
        {
            if (++j == n) {
                cout << i - j + 1 << endl;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // так как `i` будет увеличен на следующей итерации
        }
    }
}
 
// Исполнение
int main()
{
    find_substring("aabaabbaaabaabaabaabaabbaabb", "aabbaab");
    return 0;
}

//Вывод: 20