
#include <iostream>  // ����������� ���������� ��� �����-������
#include <fstream>   // ����������� ���������� ��� ������ � �������
#include <string>    // ����������� ���������� ��� ������ �� ��������
#include <Windows.h> ?// ���������� ��� ������ � ��������
// ����������� ��������� STUDENT
struct STUDENT {
    std::string surname;   // ������� ��������
    std::string initials;  // �������� ��������
    int groupNumber;       // ����� ������
    int grades[5];         // ������ (������ �� 5 ���������)
};
// ������� ��� ����������� �������������� �������
/*-������ ���������� � ��������� �����.
- ��������� ����� ������ ���� ���������.
- �� ������ ���� �������� ������ �������.*/
std::string formatSurname(const std::string& surname) {
    std::string formattedSurname = surname;
    formattedSurname[0] = std::toupper(formattedSurname[0]);
    for (size_t i = 1; i < formattedSurname.length(); ++i) {
        formattedSurname[i] = std::tolower(formattedSurname[i]);
    }
    return formattedSurname;
}

// ������� ��� ����������� �������������� ���������
/* - ������ �������� �� ��������� ���� � ������� ����� ������ �����.
- ������ ���� ��� �������� ����� ������� � �������.
- ������: "�.�."*/

std::string formatInitials(const std::string& initials) {
    std::string formattedInitials;
    for (char ch : initials) {
        if (std::isalpha(ch)) {
            formattedInitials += std::toupper(ch);
            formattedInitials += '.';
        }
    }
    return formattedInitials;
}

// ������� ��� ����� ������ � ��������
void inputStudentData(STUDENT& student) {
    std::cout << "������� �������: ";
    std::cin >> student.surname;
    student.surname = formatSurname(student.surname);

    std::cout << "������� ��������: ";
    std::cin >> student.initials;
    student.initials = formatInitials(student.initials);

    std::cout << "������� ����� ������: ";
    std::cin >> student.groupNumber;

    std::cout << "������� 5 ������: ";
    for (int& grade : student.grades) {
        std::cin >> grade;
    }
}

// ������� ��� �������� ������� ������ 2 � ��������
bool hasGradeTwo(const STUDENT& student) {
    for (int grade : student.grades) {
        if (grade == 2) {
            return true;  // ���� ���� �� ���� ������ 2, ���������� true
        }
    }
    return false;  // ���� �� ����� ������ 2 ���, ���������� false
}

// ������� ��� ������ ��������� � ������� 2
void outputStudentsWithGradeTwo(STUDENT students[], int n) {
   
    bool found = false;  // ���� ��� �������� ������� ��������� � ������� 2
    for (int i = 0; i < n; ++i) {
        if (hasGradeTwo(students[i])) {
            std::cout << students[i].surname << " " << students[i].groupNumber << std::endl;
            found = true;  // ���� ������ ������� � ������� 2, ������������� ����
        }
    }
    if (!found) {
        std::cout << "��� ��������� � ������� 2." << std::endl;  // ���������, ���� ����� ��������� ���
    }
}

// ������� ��� ������ ������ ��������� � ����
void saveToFile(STUDENT students[], int n, const std::string& filename) {
    std::ofstream file(filename);  // �������� ����� ��� ������
    if (file.is_open()) {
        for (int i = 0; i < n; ++i) {
            file << students[i].surname << " " << students[i].initials << " "
                << students[i].groupNumber << " ";
            for (int grade : students[i].grades) {
                file << grade << " ";
            }
            file << std::endl;
        }
        file.close();  // �������� �����
    }
    else {
        std::cout << "�� ������� ������� ����." << std::endl;  // ��������� �� ������ �������� �����
    }
}

int main() {
    setlocale(LC_ALL, "Russian");//������������� ������ ��� ������������� �������� ����� ��� ����������� ����������� ������ �� ������� 
    SetConsoleCP(1251);
    STUDENT students[100];  // ������ ��� �������� ������ ���������
    int n;

    std::cout << "������� ���������� ���������: ";
    std::cin >> n;  // ���� ���������� ���������

    for (int i = 0; i < n; ++i) {
        inputStudentData(students[i]);  // ���� ������ ��� ������� ��������
    }

    std::cout << "�������� � ������� 2:" << std::endl;
    outputStudentsWithGradeTwo(students, n);  // ����� ��������� � ������� 2

    saveToFile(students, n, "students.txt");  // ������ ������ ��������� � ����
    system("pause>nul");//��� ������� ���������������� ���������� ��������� �� ��� ���, ���� ������������ �� ������ �������, ����� �� ��� ������� ��������� 
    return 0;
}