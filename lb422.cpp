#include <iostream>//���������� ��� ����� � ������ ������
#include <cstdlib>// (standart library) ����������� ��� ������ � ��������� ������ ����������, ������� system()
#include <locale.h>//���������� ��� ����������� �����(� ������ ������ ��������)
#include <cmath>//���������� ��� ������ � ��������������� �����������
using namespace std;//��������� ������������ ������������ ������� � �������(��������, cout, cin) ��� �������� std
int main()
{//����� �����
	setlocale(LC_ALL, "Russian");//������������� ������ ��� ������������� �������� ����� ��� ����������� ����������� ������ �� �������
	int rows =2, cols=2, summ = 0;
	int array[2][2];
	cout << "������� �������� �������";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			cout << "������" << i << "�������" << j;
			cin >> array[i][j];
	    }
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << array[i][j];
		}
		cout << "\n";
	}
	int sum[2];
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			summ += array[i][j];
		}
		sum[j] = summ;
		summ = 0;
	}
	for (int i = 0; i < cols; i++) {
		cout << "����� ���������" << i << "������� =" << sum[i] << endl;
	}
	system("pause>nul");//��� ������� ���������������� ���������� ��������� �� ��� ���, ���� ������������ �� ������ �������, ����� �� ��� ������� ���������
	return 0;
}