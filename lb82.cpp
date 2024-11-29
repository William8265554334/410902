#include <iostream>
#include <complex>
using namespace std;

// Перегруженная функция для суммы целых чисел
int sum(int a, int b) {
    return a + b;
}

// Перегруженная функция для суммы комплексных чисел
complex<double> sum(complex<double> a, complex<double> b) {
    return a + b;
}

int main() {
    setlocale(LC_ALL, "Russian");//Устанавливает локаль для использование русского языка для корректного отображения текста на русском 
    int intA = 3;
    int intB = 7;
    cout << "Сумма целых чисел: " << sum(intA, intB) << endl;

    complex<double> complexA(1.0, 2.0); // 1 + 2i
    complex<double> complexB(3.0, 4.0); // 3 + 4i
    complex<double> result = sum(complexA, complexB);
    cout << "Сумма комплексных чисел: " << result << std::endl;
    system("pause>nul"); // Приостанавливает выполнение программы до нажатия клавиши
    return 0;
}