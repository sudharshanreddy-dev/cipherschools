#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;

    Student(string name, double grade) : name(name), grade(grade) {}
};

void addStudent(vector<Student>& students) {
    string name;
    double grade;

    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter student's grade: ";
    cin >> grade;

    students.push_back(Student(name, grade));
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    cout << "Student Records:" << endl;
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }
}

void calculateAverageGrade(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available to calculate average." << endl;
        return;
    }

    double totalGrade = 0;
    for (const auto& student : students) {
        totalGrade += student.grade;
    }

    double averageGrade = totalGrade / students.size();
    cout << "Average grade: " << averageGrade << endl;
}

void displayHighestGradeStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    const auto& highestGradeStudent = *max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.grade < b.grade;
        });

    cout << "Student with the highest grade: " << highestGradeStudent.name
         << " with grade " << highestGradeStudent.grade << endl;
}

void displayMenu() {
    cout << "\nMenu Options:" << endl;
    cout << "1. Add a new student" << endl;
    cout << "2. Display all student records" << endl;
    cout << "3. Calculate average grade" << endl;
    cout << "4. Find the student with the highest grade" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please try again." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                calculateAverageGrade(students);
                break;
            case 4:
                displayHighestGradeStudent(students);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
