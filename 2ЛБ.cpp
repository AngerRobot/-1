#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class STUDENT {
private:
    std::string fullName;
    char gender;
    int birthYear;
    int admissionYear;
    std::string recordBookNumber;
    double averageGrade;

public:
    STUDENT(std::string name, char gen, int birth, int admission, std::string recordNumber)
        : fullName(name), gender(gen), birthYear(birth), admissionYear(admission), recordBookNumber(recordNumber), averageGrade(0.0) {}

    void setFullName(const std::string& name) { fullName = name; }
    void setGender(char gen) { gender = gen; }
    void setBirthYear(int year) { birthYear = year; }
    void setAdmissionYear(int year) { admissionYear = year; }
    void setRecordBookNumber(const std::string& number) { recordBookNumber = number; }
    void setAverageGrade(double grade) { averageGrade = grade; }

    void updateAverageGrade(const std::vector<int>& grades) {
        double sum = 0.0;
        for (int grade : grades) {
            sum += grade;
        }
        averageGrade = sum / grades.size();
    }

    double getAverageGrade() const { return averageGrade; }

    void displayInfo() const {
        std::cout << "ФИО: " << fullName << ", Пол: " << gender << ", Год рождения: " << birthYear
                  << ", Год поступления: " << admissionYear << ", Номер зачетки: " << recordBookNumber
                  << ", Средний балл: " << averageGrade << std::endl;
    }
};

std::vector<int> generateRandomGrades(int count) {
    std::vector<int> grades;
    for (int i = 0; i < count; ++i) {
        grades.push_back(rand() % 5 + 1); 
    }
    return grades;
}

bool compareStudents(const STUDENT& s1, const STUDENT& s2) {
    return s1.getAverageGrade() > s2.getAverageGrade();
}

int main() {
    srand(static_cast<unsigned>(time(0))); 
    STUDENT students[3] = {
        STUDENT("Иванов Иван Иванович", 'M', 2000, 2018, "123456"),
        STUDENT("Петрова Анна Сергеевна", 'F', 1999, 2019, "654321"),
        STUDENT("Сидоров Алексей Викторович", 'M', 2001, 2020, "987654")
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::vector<int> grades = generateRandomGrades(4);
            students[j].updateAverageGrade(grades);
        }
    }

    STUDENT* heapStudent = new STUDENT("Кузнецова Мария Павловна", 'F', 2002, 2021, "112233");
    std::vector<int> heapGrades = generateRandomGrades(4);
    heapStudent->updateAverageGrade(heapGrades);

    std::vector<STUDENT> studentVector(students, students + 3);
    studentVector.push_back(*heapStudent);
    
    std::sort(studentVector.begin(), studentVector.end(), compareStudents);

    std::cout << "Результаты студентов (по убыванию среднего балла):" << std::endl;
    for (const auto& student : studentVector) {
        student.displayInfo();
    }

    delete heapStudent; 

    return 0;
}