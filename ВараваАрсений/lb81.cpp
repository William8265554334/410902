#include <iostream> // ���������� ��� ����� � ������ ������
#include <cstdlib>  // ���������� ��� ������ � ��������� ������ ����������, ������� system()
#include <locale.h> // ���������� ��� ����������� ����� (� ������ ������ ��������)
#include <string.h> // ��� ������ �� ��������
#include <cmath>    // ���������� ��� ������ � ��������������� �����������

using namespace std; // ��������� ������������ ����������� ������� � ������� (��������, cout, cin) ��� �������� std

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
            cout<< "����� " << i << " ����������� " << digitCount[i] << " ���.\n";
            hasDuplicates = true;
        }
    }

    if (!hasDuplicates) {
        cout << "���� 3 ��������.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // ������������� ������ ��� ������������� �������� ����� ��� ����������� ����������� ������

    for (int num = 1000; num < 10000; num++) {
        cout << num;
        countDuplicateDigits(num);
    }

    system("pause>nul"); // ���������������� ���������� ���������, ������ ������� �������
    return 0;
}