#include <iostream>
#include <algorithm>
using namespace std;

int find_substring(string str, string pattern) {

	// Исключаем вариант пустой сторки. Она не должна быть такой же, как её создатель
	if( str.size() == 0 || pattern.size() == 0)
		return -1;

	// Вычисляем функцию отказа
	int failure[pattern.size()];
	std::fill( failure, failure+pattern.size(), -1);

	for(int r=1, l=-1; r<pattern.size(); r++) {

		while( l != -1 && pattern[l+1] != pattern[r])
			l = failure[l];

		if( pattern[l+1] == pattern[r])
			failure[r] = ++l;
	}

	// Ищем паттерн
	int tail = -1;
	for(int i=0; i<str.size(); i++) {

		while( tail != -1 && str[i] != pattern[tail+1])
			tail = failure[tail];

		if( str[i] == pattern[tail+1])
			tail++;

		if( tail == pattern.size()-1)
			return i - tail;
	}

	return -1;
}

int main() {

	cout << find_substring("abcd", "abcd") << endl;
	cout << find_substring("abcd", "ab") << endl;
	cout << find_substring("ab", "abcd") << endl;
	cout << find_substring("ababc", "abc") << endl;

	return 0;
}