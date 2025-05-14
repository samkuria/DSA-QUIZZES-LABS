#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Grade structure
struct Grade {
    int mark;
    char the_grade;

    // Constructor to calculate grade automatically
    Grade(int m = 0) : mark(m) {
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }

    // Grade cannot be modified after calculation
    void setMark(int m) {
        if (mark == 0) { // Only allow setting if mark wasn't set before
            mark = m;
            if (mark > 69) the_grade = 'A';
            else if (mark > 59) the_grade = 'B';
            else if (mark > 49) the_grade = 'C';
            else if (mark > 39) the_grade = 'D';
            else the_grade = 'E';
        }
    }
};

// Course structure
struct Course {
    string course_code;
    string course_name;
};

// Student structure
struct Student {
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated = false;
};

// Function prototypes
void addStudent(Student students[], int& count);
void editStudent(Student students[], int count);
void addMarks(Student students[], int count);
void displayStudents(const Student students[], int count);

int main() {
    Student students[40];
    int studentCount = 0;
    int choice;

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Add Marks and Calculate Grades\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarks(students, studentCount);
                break;
            case 4:
                displayStudents(students, studentCount);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void addStudent(Student students[], int& count) {
    if (count >= 40) {
        cout << "Maximum number of students reached (40).\n";
        return;
    }

    Student s;
    cout << "\nEnter student details:\n";

    cout << "Registration Number: ";
    cin.ignore();
    getline(cin, s.reg_number);

    cout << "Name: ";
    getline(cin, s.name);

    cout << "Age: ";
    cin >> s.age;

    cout << "Course Code: ";
    cin.ignore();
    getline(cin, s.course.course_code);

    cout << "Course Name: ";
    getline(cin, s.course.course_name);

    // Initialize grades as not calculated
    s.grades = Grade();
    s.grades_calculated = false;

    students[count++] = s;
    cout << "Student added successfully!\n";
}

void editStudent(Student students[], int count) {
    if (count == 0) {
        cout << "No students available to edit.\n";
        return;
    }

    string regNum;
    cout << "Enter registration number of student to edit: ";
    cin.ignore();
    getline(cin, regNum);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].reg_number == regNum) {
            found = true;
            cout << "\nEditing student " << students[i].name << ":\n";

            cout << "New Name (current: " << students[i].name << "): ";
            getline(cin, students[i].name);

            cout << "New Age (current: " << students[i].age << "): ";
            cin >> students[i].age;

            cout << "New Course Code (current: " << students[i].course.course_code << "): ";
            cin.ignore();
            getline(cin, students[i].course.course_code);

            cout << "New Course Name (current: " << students[i].course.course_name << "): ";
            getline(cin, students[i].course.course_name);

            cout << "Student details updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with registration number " << regNum << " not found.\n";
    }
}

void addMarks(Student students[], int count) {
    if (count == 0) {
        cout << "No students available to add marks.\n";
        return;
    }

    string regNum;
    cout << "Enter registration number of student to add marks: ";
    cin.ignore();
    getline(cin, regNum);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].reg_number == regNum) {
            found = true;
            if (students[i].grades_calculated) {
                cout << "Grades for this student have already been calculated and cannot be changed.\n";
                return;
            }

            int mark;
            cout << "Enter mark (0-100) for " << students[i].name << ": ";
            cin >> mark;

            while (mark < 0 || mark > 100) {
                cout << "Invalid mark. Please enter a value between 0 and 100: ";
                cin >> mark;
            }

            students[i].grades.setMark(mark);
            students[i].grades_calculated = true;
            cout << "Grade calculated and saved: " << students[i].grades.the_grade << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with registration number " << regNum << " not found.\n";
    }
}

void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nList of Students:\n";
    cout << "-----------------------------------------------------------------\n";
    cout << "Reg No.    Name                Age  Course Code  Course Name       Mark  Grade\n";
    cout << "-----------------------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << students[i].reg_number << "  "
             << students[i].name << string(20 - students[i].name.length(), ' ') << "  "
             << students[i].age << "  "
             << students[i].course.course_code << string(12 - students[i].course.course_code.length(), ' ') << "  "
             << students[i].course.course_name << string(15 - students[i].course.course_name.length(), ' ') << "  ";

        if (students[i].grades_calculated) {
            cout << students[i].grades.mark << "     " << students[i].grades.the_grade;
        } else {
            cout << "N/A     N/A";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------\n";
}
