/* Program name: person.h
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: Create Person class
*/
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include "lesson.h"

using namespace std;

class Person {
public:
    // Constructor
    Person(string fname, string lname);

    // Destructor
    virtual ~Person();

    // Getters
    string getFirstName() const;
    string getLastName() const;

    // Setters
    void setFirstName(const string &fname);
    void setLastName(const string &lname);

    // Virtual functions (pure virtual)
    virtual void print() const = 0;

    // Friend input/output stream operators
    friend istream& operator>>(istream& in, Person& person);
    friend ostream& operator<<(ostream& out, const Person& person);

private:
    string firstName;
    string lastName;
};

class Student;
class Recipient : public Person {
public:
    // Constructors
    Recipient();
    Recipient(string fname, string lname);

    // Destructor
    ~Recipient();

    // Getters
    vector<Student> getStudents() const;

    // Others
    void addStudent(const Student& student);
    void print() const override;
    float calculateTotal() const;  // Calculate total tuition of all students

private:
    vector<Student> students;
};

class Student : public Person {
public:
    // Constructors
    Student();
    Student(string fname, string lname);

    // Destructor
    ~Student();

    // Getters
    float getStudentTotalTuition() const;

    // Setters
    void setStudentTotalTuition(float total);

    // Others
    void addLesson(Lesson& lesson);
    vector<Lesson> getLessons() const;

    void print() const override;

private:
    float studentTotalTuition;
    vector<Lesson> lessons;
};

#endif // PERSON_H
