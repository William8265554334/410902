
#include <iostream>  // Подключение библиотеки для ввода-вывода
#include <fstream>   // Подключение библиотеки для работы с файлами
#include <string>    // Подключение библиотеки для работы со строками
#include <Windows.h> ?// Библиотека для работы с консолью
// Определение структуры STUDENT
struct STUDENT {
    std::string surname;   // Фамилия студента
    std::string initials;  // Инициалы студента
    int groupNumber;       // Номер группы
    int grades[5];         // Оценки (массив из 5 элементов)
};
// Функция для правильного форматирования фамилии
/*-Должна начинаться с заглавной буквы.
- Остальные буквы должны быть строчными.
- Не должно быть пробелов внутри фамилии.*/
std::string formatSurname(const std::string& surname) {
    std::string formattedSurname = surname;
    formattedSurname[0] = std::toupper(formattedSurname[0]);
    for (size_t i = 1; i < formattedSurname.length(); ++i) {
        formattedSurname[i] = std::tolower(formattedSurname[i]);
    }
    return formattedSurname;
}

// Функция для правильного форматирования инициалов
/* - Должны состоять из заглавных букв с точками после каждой буквы.
- Должны быть без пробелов между буквами и точками.
- Пример: "Е.Е."*/

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

// Функция для ввода данных о студенте
void inputStudentData(STUDENT& student) {
    std::cout << "Введите фамилию: ";
    std::cin >> student.surname;
    student.surname = formatSurname(student.surname);

    std::cout << "Введите инициалы: ";
    std::cin >> student.initials;
    student.initials = formatInitials(student.initials);

    std::cout << "Введите номер группы: ";
    std::cin >> student.groupNumber;

    std::cout << "Введите 5 оценок: ";
    for (int& grade : student.grades) {
        std::cin >> grade;
    }
}

// Функция для проверки наличия оценки 2 у студента
bool hasGradeTwo(const STUDENT& student) {
    for (int grade : student.grades) {
        if (grade == 2) {
            return true;  // Если хотя бы одна оценка 2, возвращаем true
        }
    }
    return false;  // Если ни одной оценки 2 нет, возвращаем false
}

// Функция для вывода студентов с оценкой 2
void outputStudentsWithGradeTwo(STUDENT students[], int n) {
   
    bool found = false;  // Флаг для проверки наличия студентов с оценкой 2
    for (int i = 0; i < n; ++i) {
        if (hasGradeTwo(students[i])) {
            std::cout << students[i].surname << " " << students[i].groupNumber << std::endl;
            found = true;  // Если найден студент с оценкой 2, устанавливаем флаг
        }
    }
    if (!found) {
        std::cout << "Нет студентов с оценкой 2." << std::endl;  // Сообщение, если таких студентов нет
    }
}

// Функция для записи данных студентов в файл
void saveToFile(STUDENT students[], int n, const std::string& filename) {
    std::ofstream file(filename);  // Открытие файла для записи
    if (file.is_open()) {
        for (int i = 0; i < n; ++i) {
            file << students[i].surname << " " << students[i].initials << " "
                << students[i].groupNumber << " ";
            for (int grade : students[i].grades) {
                file << grade << " ";
            }
            file << std::endl;
        }
        file.close();  // Закрытие файла
    }
    else {
        std::cout << "Не удалось открыть файл." << std::endl;  // Сообщение об ошибке открытия файла
    }
}

int main() {
    setlocale(LC_ALL, "Russian");//Устанавливает локаль для использование русского языка для корректного отображения текста на русском 
    SetConsoleCP(1251);
    STUDENT students[100];  // Массив для хранения данных студентов
    int n;

    std::cout << "Введите количество студентов: ";
    std::cin >> n;  // Ввод количества студентов

    for (int i = 0; i < n; ++i) {
        inputStudentData(students[i]);  // Ввод данных для каждого студента
    }

    std::cout << "Студенты с оценкой 2:" << std::endl;
    outputStudentsWithGradeTwo(students, n);  // Вывод студентов с оценкой 2

    saveToFile(students, n, "students.txt");  // Запись данных студентов в файл
    system("pause>nul");//Эта команда приостанавливает выполнение программы до тех пор, пока пользователь не нажмет клавишу, чтобы он мог увидеть результат 
    return 0;
}