//
// Created by Younghyun Lee on 10/7/24.
//

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    // Constructor
    Person(string fname, string lname);

    // Destructor
    ~Person();

    // Getters
    string getFirstName() const;
    string getLastName() const;

    // Setters
    void setFirstName(const string &fname);
    void setLastName(const string &lname);

    // others
    friend istream& operator>>(istream& in, Person& person);
    friend ostream& operator<<(ostream& out, const Person& person);

private:
    string firstName;
    string lastName;
};

#endif // PERSON_H
