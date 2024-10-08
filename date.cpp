/* Program name: date.cpp
* Author: Younghyun Lee
* Date last updated: 9/22/2024
* Purpose: Create Date class
*/
#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

string weekdayToString(weekdayType day) {
    switch(day) {
        case SUNDAY:    return "Sunday";
        case MONDAY:    return "Monday";
        case TUESDAY:   return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY:  return "Thursday";
        case FRIDAY:    return "Friday";
        case SATURDAY:  return "Saturday";
        default:        return "UNKNOWN";
    }
}

// Helper method
bool date::isLeapYearHelper(int year) {
    if (year % 4 ==0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int date::daysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return isLeapYearHelper(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

bool date::isValidDate(int month, int day, int year) {
    if (year < 0) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }

    // valid day determined by the month and year
    int maxDay = daysInMonth(month, year);
    if (day < 1 || day > maxDay) {
        return false;
    }
    return true;
}

// Constructor
date::date(int month, int day, int year)
{
    if (!isValidDate(month, day, year)) {
        cout << "Invalid date. Setting date to January 1, 2000." << endl;
        this -> month = 1;
        this -> day = 1;
        this -> year = 2000;
    }
    else {
        this -> month = month;
        this -> day = day;
        this -> year = year;
    }
}

// Getters
int date::getDay() const
{
    return day;
}

int date::getMonth() const
{
    return month;
}

int date::getYear() const
{
    return year;
}

// Setters
void date::setDay(int day)
{
    if (isValidDate(month, day, year)) {
        this -> day = day;
    }
    else {
        cout << "Invalid day." << endl;
    }
}

void date::setMonth(int month)
{
    if (isValidDate(month, day, year)) {
        this -> month = month;
    }
    else {
        cout << "Invalid month." << endl;
    }
}

void date::setYear(int year)
{
    if (isValidDate(month, day, year)) {
        this -> year = year;
    }
    else {
        cout << "Invalid year." << endl;
    }
}

// Other
bool date::isLeapYear() {
    return isLeapYearHelper(year);
}

// Operator functions
bool date::operator==(const date& otherDate) const {
    return (day == otherDate.day) && (month == otherDate.month) && (year == otherDate.year);
}

bool date::operator!=(const date& otherDate) const {
    // use the overloaded == operator
    return !(*this == otherDate);
}

bool date::operator<(const date& otherDate) const {
    // use the overloaded != operator
    if (year != otherDate.year)
        return year < otherDate.year;
    if (month != otherDate.month)
        return month < otherDate.month;
    return day < otherDate.day;
}

bool date::operator<=(const date& otherDate) const {
    // use the overloaded < and == operator
    return (*this < otherDate) || (*this == otherDate);
}

bool date::operator>(const date& otherDate) const {
    // use the overloaded < operator
    return otherDate < *this;
}

bool date::operator>=(const date& otherDate) const {
    // use the overloaded > and == operator
    return (*this > otherDate) || (*this == otherDate);
}

// Helper methods for ++, -- operator functions
void date::incrementDate() {
    int maxDay = daysInMonth(month, year);
    day++;
    if (day > maxDay) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void date::decrementDate() {
    // edge cases
    if (year == 0 && month == 1 && day == 1) {
        // Cannot decrement beyond this date
        return;
    }

    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            if (year > 0) {
                year--;
            }
        }
        day = daysInMonth(month, year);
    }
}

// +, - operator functions
// add a date + integer
date& date::operator+(int daysToAdd) {
    for (int i = 0; i < daysToAdd; ++i) {
        incrementDate();
    }
    return *this;
}

// subtract a date - integer
date& date::operator-(int daysToSub) {
    for (int i = 0; i < daysToSub; ++i) {
        decrementDate();
    }
    return *this;
}

// ++, -- operator functions
date date::operator++() {
    incrementDate();
    return *this;
}

date date::operator++(int) {
    // Save the current date state (before incrementing) to return after increment
    date temp = *this;
    incrementDate();
    return temp;
}

date date::operator--() {
    decrementDate();
    return *this;
}

date date::operator--(int) {
    date temp = *this;
    decrementDate();
    return temp;
}

// Friend functions
// add integer + a date
date& operator+(int daysToAdd, date& addToDate) {
    return addToDate + daysToAdd;
}

// subtract integer - a date
date& operator-(int daysToSub, date& subFromDate) {
    return subFromDate - daysToSub;
}

istream& operator>>(istream& in, date& dateToFill) {
    // read three numbers from the input stream
    int month, day, year;
    in >> month >> day >> year;
    if (!dateToFill.isValidDate(month, day, year)) {
        cout << "Invalid date input." << endl;
    } else {
        dateToFill.month = month;
        dateToFill.day = day;
        dateToFill.year = year;
    }
    return in;
}

ostream& operator<<(ostream& out, date& dateToPrint) {
    // output the date is ISO-8601 format yyyy-mm-dd
    out << setfill('0') << setw(4) << dateToPrint.year << '-'
        << setw(2) << dateToPrint.month << '-'
        << setw(2) << dateToPrint.day;
    return out;
}

// Destructor
date::~date() {}
