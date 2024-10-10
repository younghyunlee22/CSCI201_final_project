/* Program name: person.cpp
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: Create Person class
*/
#include "person.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constructor
Person::Person(string fname, string lname) : firstName(fname), lastName(lname) {
}

// Destructor
Person::~Person() {
}

// Getters
string Person::getFirstName() const {
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

// Setters
void Person::setFirstName(const string &fname) {
    firstName = fname;
}

void Person::setLastName(const string &lname) {
    lastName = lname;
}

// Overloading >> operator for input
istream& operator>>(istream& in, Person& person) {
    in >> person.firstName >> person.lastName;
    return in;
}

// Overloading << operator for output
ostream& operator<<(ostream& out, const Person& person) {
    out << person.firstName << " " << person.lastName << " ";
    return out;
}

// Recipient constructor
Recipient::Recipient() : Person("", "") {}

Recipient::Recipient(string fname, string lname) : Person(fname, lname) {}

Recipient::~Recipient() {}

// Add a student to the recipient's list
void Recipient::addStudent(const Student& student) {
    students.push_back(student);
}

// Get the list of students
vector<Student> Recipient::getStudents() const {
    return students;
}

// Print recipient details
void Recipient::print() const {
    cout << "\n** Invoice for: " << getFirstName() << " " << getLastName() << " **\n";
    cout << students.size() << " Students:\n";

    for (size_t i = 0; i < students.size(); ++i) {
        cout << "Student " << i + 1 << ". ";
        students[i].print();
    }
    cout << "* * * Invoice total: $" << fixed << setprecision(2) << calculateTotal() << "\n";
}

// Calculate the total cost for all students
float Recipient::calculateTotal() const {
    float total = 0.0f;
    for (const auto& student : students) {
        total += student.getStudentTotalTuition();
    }
    return total;
}

// Student constructor
Student::Student() : Person("", ""), studentTotalTuition(0.0f) {}

Student::Student(string fname, string lname) : Person(fname, lname), studentTotalTuition(0.0f) {}

Student::~Student() {}

float Student::getStudentTotalTuition() const {
    return studentTotalTuition;
}

void Student::setStudentTotalTuition(float total) {
    this->studentTotalTuition = total;
}

vector<Lesson> Student::getLessons() const {
    return lessons;
}

// Add a lesson and update total lesson price
void Student::addLesson(Lesson& lesson){
    lessons.push_back(lesson);
    studentTotalTuition += lesson.calculateTotalLessonPrice();
}

// Print student details
void Student::print() const {
    cout << getFirstName() << " " << getLastName() << "\n";
    cout << "Lessons:\n";

    for (size_t i = 0; i < lessons.size(); ++i) {
        cout << i + 1 << ". ";
        lessons[i].print();
    }

    cout << "*Subtotal: $" << fixed << setprecision(2) << studentTotalTuition << "\n" << endl;
}
