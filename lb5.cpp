#include <iostream>//Библиотека для ввода и вывода данных
#include <cstdlib>// (standart library) библлиотека для работы с функциями общего назначения, включая system()
#include <locale.h>//Библиотека для локализации языка(В данном случае русского)
#include <cmath>//Библиотека для работы с математическими выражениями
using namespace std;//Позволяет использовать стандартныее функции и объекты(например, cout, cin) без префикса std
// Задание найти сумму всех членов последовательности от 1 до n (-1)^(n+1)/n*(n+1)
int main()
{//Точка входа
	setlocale(LC_ALL, "Russian");//Устанавливает локаль для использование русского языка для корректного отображения текста на русском
	int rows, cols, summ=0;
	cout << "Введите количество строк";
	cin >> rows;
	cout << "Введите количество столбцов";
	cin >> cols;
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new int[cols];
	}
	cout << "Введите элементы массива";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "Строка" << i << "Столбец" << j;
			cin >> array[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout<< array[i][j];
		}
		cout << "\n";
	}
	int* sum = new int[cols];
	for (int j = 0; j < cols; j++){
		for (int i = 0; i < rows; i++) {
			summ += array[i][j];
		}
		sum[j] = summ;
		summ = 0;
	}
	for (int i = 0; i < cols; i++) {
		cout <<"Сумма элементов"<<i<<"столбца ="<<sum[i] << endl;
	}
		delete[]array;
		delete[]sum;
	system("pause>nul");//Эта команда приостанавливает выполнение программы до тех пор, пока пользователь не нажмет клавишу, чтобы он мог увидеть результат
	return 0;
}