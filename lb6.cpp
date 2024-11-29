#include <iostream> // ���������� ��� ����� � ������ ������
#include <cstdlib>  // ���������� ��� ������ � ��������� ������ ����������, ������� system()
#include <locale.h> // ���������� ��� ����������� ����� (� ������ ������ ��������)
#include <sstream>  // ���������� ��� ������ � �������� �����
#include <cstring>  // ���������� ��� ������ � C-��������, ������� strlen

using namespace std; // ��������� ������������ ����������� ������� � ������� (��������, cout, cin) ��� �������� std

int main() {
    setlocale(LC_ALL, "Russian"); // ������������� ������ ��� ������������� �������� ����� ��� ����������� ����������� ������ �� �������

    const char* str1 = "No i dont want"; // ������ ������ ��� ���������
    const char* str2 = "Yes i will do it"; // ������ ������ ��� ���������

    // ����������� ����� �����
    int a = strlen(str1); // ����� ������ ������
    int b = strlen(str2); // ����� ������ ������

    // ��������, ����� ������ ������
    if (a > b) {
        cout << str2 << endl; // ����� ������ ������, ���� ��� ������
        stringstream ss(str2); // �������� ������ ����� ��� ������ ������
        string word, result; // ���������� ��� �������� ���� � ����������
        while (ss >> word) { // ������ ���� �� ������
            if (!islower(word[0])) { // ��������, ��� ����� �� ���������� � ��������� �����
                if (!result.empty()) result += " "; // ���������� ������� ����� �������
                result += word; // ���������� ����� � ���������
            }
        }
        cout << "���������: " << result << endl; // ����� ���������� ������
    }
    else if (b > a) {
        cout << str1 << endl; // ����� ������ ������, ���� ��� ������
        stringstream ss(str1); // �������� ������ ����� ��� ������ ������
        string word, result; // ���������� ��� �������� ���� � ����������
        while (ss >> word) { // ������ ���� �� ������
            if (!islower(word[0])) { // ��������, ��� ����� �� ���������� � ��������� �����
                if (!result.empty()) result += " "; // ���������� ������� ����� �������
                result += word; // ���������� ����� � ���������
            }
        }
        cout << "���������: " << result << endl
