//
// Created by Younghyun Lee on 10/7/24.
//

#include "person.h"

#include <iostream>
#include <string>

// Constructor implementation
Person::Person(string fname, string lname) : firstName(fname), lastName(lname) {
}

// Destructor implementation
Person::~Person() {
}

// Getter implementations
string Person::getFirstName() const {
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

// Setter implementations
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
    out << person.firstName << " " << person.lastName;
    return out;
}
