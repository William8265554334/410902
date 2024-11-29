#include <iostream> // Библиотека для ввода и вывода данных
#include <cstdlib>  // Библиотека для работы с функциями общего назначения, включая system()
#include <locale.h> // Библиотека для локализации языка (в данном случае русского)
#include <string.h> // Для работы со строками
#include <cmath>    // Библиотека для работы с математическими выражениями

using namespace std; // Позволяет использовать стандартные функции и объекты (например, cout, cin) без префикса std

void countDuplicateDigits(int number) {
    int digitCount[10] = { 0 };

    while (number > 0) {
        int digit = number % 10;
        digitCount[digit]++;
        number /= 10;
    }

    bool hasDuplicates = false;
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > 2) {
            cout<< "Цифра " << i << " встречается " << digitCount[i] << " раз.\n";
            hasDuplicates = true;
        }
    }

    if (!hasDuplicates) {
        cout << "Нету 3 повторов.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливает локаль для использования русского языка для корректного отображения текста

    for (int num = 1000; num < 10000; num++) {
        cout << num;
        countDuplicateDigits(num);
    }

    system("pause>nul"); // Приостанавливает выполнение программы, ожидая нажатия клавиши
    return 0;
}