//
// Created by Younghyun Lee on 10/7/24.
//

#include "person.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constructor implementation
Person::Person(string fname, string lname) : firstName(fname), lastName(lname) {
}

// Destructor implementation
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

// // Overloading >> operator for input
// istream& operator>>(istream& in, Person& person) {
//     in >> person.firstName >> person.lastName;
//     return in;
// }
//
// // Overloading << operator for output
// ostream& operator<<(ostream& out, const Person& person) {
//     out << person.firstName << " " << person.lastName;
//     return out;
// }

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
    cout << "Recipient: " << getFirstName() << " " << getLastName() << "\n";
    cout << "Students:\n";

    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". ";
        students[i].print();
    }

    cout << "Total Invoice for " << getFirstName() << ": $" << fixed << setprecision(2) << calculateTotal() << "\n";
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
Student::Student() : Person("", ""), age(0), studentTotalTuition(0.0f) {}

Student::Student(string fname, string lname, int age) : Person(fname, lname), age(age), studentTotalTuition(0.0f) {}

Student::~Student() {}

// Get age
int Student::getAge() const {
    return age;
}

float Student::getStudentTotalTuition() const {
    return studentTotalTuition;
}

// Set age
void Student::setAge(int age) {
    this->age = age;
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
    cout << getFirstName() << " " << getLastName() << ", Age: " << getAge() << "\n";
    cout << "Lessons:\n";

    for (size_t i = 0; i < lessons.size(); ++i) {
        cout << i + 1 << ". ";
        lessons[i].print();
    }

    cout << "Total Lesson Price: $" << fixed << setprecision(2) << studentTotalTuition << "\n";
}
