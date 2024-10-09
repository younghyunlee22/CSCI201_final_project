#include <iostream>
#include "person.h"
#include "lesson.h"
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, weekdayType> firstWeekdayOfMonth {
        {10, TUESDAY},
        {11, FRIDAY},
        {12, SUNDAY}
};

int main() {
    string fname, lname;
    int age;

    // Create a Recipient object (since Person is abstract)
    cout << "Enter recipient's first name: ";
    cin >> fname;
    cout << "Enter recipient's last name: ";
    cin >> lname;

    Recipient recipient(fname, lname);

    // Add a student
    cout << "Enter student's first name: ";
    cin >> fname;
    cout << "Enter student's last name: ";
    cin >> lname;
    cout << "Enter student's age: ";
    cin >> age;
    Student student1(fname, lname, 15);  // Example age
    Student student2(fname, lname, 15);

    // Add lessons to the student
    Lesson lesson1(MONDAY, 60, 30.0f, 4);  // Monday, 60 min, $30/hour, 4 lessons
    student1.addLesson(lesson1);

    Lesson lesson2(WEDNESDAY, 45, 35.0f, 5);  // Wednesday, 45 min, $35/hour, 5 lessons
    student1.addLesson(lesson2);

    Lesson lesson3(MONDAY, 60, 35.0f, 4);  // Monday, 60 min, $30/hour, 4 lessons
    student2.addLesson(lesson3);

    Lesson lesson4(WEDNESDAY, 30, 35.0f, 5);  // Wednesday, 45 min, $35/hour, 5 lessons
    student2.addLesson(lesson4);
    // Add the student to the recipient
    recipient.addStudent(student1);
    recipient.addStudent(student2);
    cout << "Number of students in recipient: " << recipient.getStudents().size() << endl;

    // Print details
    recipient.print();

    return 0;
}
