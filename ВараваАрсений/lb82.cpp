#include <iostream>
#include <complex>
using namespace std;

// ������������� ������� ��� ����� ����� �����
int sum(int a, int b) {
    return a + b;
}

// ������������� ������� ��� ����� ����������� �����
complex<double> sum(complex<double> a, complex<double> b) {
    return a + b;
}

int main() {
    setlocale(LC_ALL, "Russian");//������������� ������ ��� ������������� �������� ����� ��� ����������� ����������� ������ �� ������� 
    int intA = 3;
    int intB = 7;
    cout << "����� ����� �����: " << sum(intA, intB) << endl;

    complex<double> complexA(1.0, 2.0); // 1 + 2i
    complex<double> complexB(3.0, 4.0); // 3 + 4i
    complex<double> result = sum(complexA, complexB);
    cout << "����� ����������� �����: " << result << std::endl;
    system("pause>nul"); // ���������������� ���������� ��������� �� ������� �������
    return 0;
}