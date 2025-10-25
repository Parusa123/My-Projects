#include <iostream>
#include <string>
using namespace std;

//  Base Class 
class Person {
protected:
    string name;
public:
    // Default constructor
    Person() { name = "Unknown"; }

    // Parameterized constructor
    Person(string n) { name = n; }

    // Virtual destructor
    virtual ~Person() { }
};

//  Derived Class: Student 
class Student : public Person {
private:
    int rollNo;
    string department;
    int semester;
    int marks[5];       // Array to store marks of 5 subjects
    int total;
    float percentage;
    char grade;

public:
    // Default constructor
    Student() : Person() {
        rollNo = 0;
        department = "";
        semester = 0;
        for (int i = 0; i < 5; i++) marks[i] = 0;
        total = 0;
        percentage = 0;
        grade = 'F';
    }

    // Function to input details
    void input() {
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Semester: ";
        cin >> semester;

        cout << "Enter marks of 5 subjects: ";
        total = 0;
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            total += marks[i];
        }
        calculateResult();
    }

    // Calculate total, percentage, and grade
    void calculateResult() {
        percentage = total / 5.0;

        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'F';
    }

    // Display short student info
    void display() {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Dept: " << department
             << " | Sem: " << semester
             << " | %: " << percentage
             << " | Grade: " << grade << endl;
    }

    // Generate full report card
    void reportCard() {
        cout << "\n===== Report Card =====\n";
        cout << "Name: " << name
             << "\nRoll: " << rollNo
             << "\nDepartment: " << department
             << "\nSemester: " << semester
             << "\nMarks: ";
        for (int i = 0; i < 5; i++) cout << marks[i] << " ";
        cout << "\nTotal: " << total
             << "\nPercentage: " << percentage
             << "\nGrade: " << grade << endl;
        cout << "***\n";
    }

    // Get roll number
    int getRollNo() { return rollNo; }

    // Modify student record
    void modify() {
        cout << "Re-enter details:\n";
        input();
    }
};

//  Global Database 
Student students[100];   // Array of student objects
int studentCount = 0;    // Current number of students

// Functions 
void addStudent() {
    students[studentCount].input();
    studentCount++;
}

void displayAll() {
    if (studentCount == 0) cout << "No records!\n";
    else {
        for (int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }
}

void searchStudent() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            students[i].display();
            return;
        }
    }
    cout << "Student not found!\n";
}

void modifyStudent() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            students[i].modify();
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            // Shift array elements to delete record
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Record deleted!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void generateReportCard() {
    int roll;
    cout << "Enter roll no: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNo() == roll) {
            students[i].reportCard();
            return;
        }
    }
    cout << "Student not found!\n";
}

//  Main Menu 
int main() {
    int choice;
    do {
        cout << "\n Student Management System \n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Modify Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Generate Report Card\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: generateReportCard(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}