#include <iostream>//���������� ��� ����� � ������ ������
#include <cstdlib>// (standart library) ����������� ��� ������ � ��������� ������ ����������, ������� system()
#include <locale.h>//���������� ��� ����������� �����(� ������ ������ ��������)
#include <cmath>//���������� ��� ������ � ��������������� �����������
using namespace std;//��������� ������������ ������������ ������� � �������(��������, cout, cin) ��� �������� std
// ������� ����� ����� ���� ������ ������������������ �� 1 �� n (-1)^(n+1)/n*(n+1)
int main()
{//����� �����
	setlocale(LC_ALL, "Russian");//������������� ������ ��� ������������� �������� ����� ��� ����������� ����������� ������ �� �������
	int rows, cols, summ=0;
	cout << "������� ���������� �����";
	cin >> rows;
	cout << "������� ���������� ��������";
	cin >> cols;
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new int[cols];
	}
	cout << "������� �������� �������";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << "������" << i << "�������" << j;
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
		cout <<"����� ���������"<<i<<"������� ="<<sum[i] << endl;
	}
		delete[]array;
		delete[]sum;
	system("pause>nul");//��� ������� ���������������� ���������� ��������� �� ��� ���, ���� ������������ �� ������ �������, ����� �� ��� ������� ���������
	return 0;
}