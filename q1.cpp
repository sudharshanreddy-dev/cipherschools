#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks[3];
};

int main() {
    
    Student *student = new Student;
    cout << "Enter student's name: ";
    getline(cin, student->name);

    cout << "Enter student's roll number: ";
    cin >> student->rollNo;

    cout << "Enter marks for 3 subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> student->marks[i];
    }

    float average = 0.0;
    for (int i = 0; i < 3; i++) {
        average += student->marks[i];
    }
    average /= 3;

    cout << "\nStudent's Details:\n";
    cout << "Name: " << student->name << endl;
    cout << "Roll Number: " << student->rollNo << endl;
    cout << "Marks: ";
    for (int i = 0; i < 3; i++) {
        cout << fixed << setprecision(2) << student->marks[i] << " ";
    }
    cout << "\nAverage Marks: " << fixed << setprecision(2) << average << endl;

    delete student;

    return 0;
}
