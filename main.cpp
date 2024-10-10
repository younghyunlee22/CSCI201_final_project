/* Program name: main.cpp
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: This program creates an invoice for my Korean language tutoring business.
*         It asks for the month of the invoice, the recipient's name, and the students' names.
*         It then asks for the day of the week, duration, and hourly fee for each student's lesson.
*         At the end, it prints the invoice.
*/

#include <iostream>
#include <unordered_map>
#include <cctype>

#include "person.h"
#include "lesson.h"

using namespace std;

unordered_map<int, weekdayType> firstWeekdayOfMonth2024 {
    {1, MONDAY},
    {2, THURSDAY},
    {3, FRIDAY},
    {4, MONDAY},
    {5, WEDNESDAY},
    {6, SATURDAY},
    {7, MONDAY},
    {8, THURSDAY},
    {9, SUNDAY},
    {10, TUESDAY},
    {11, FRIDAY},
    {12, SUNDAY}
};

// Function to validate that the string contains only alphabetic characters
void stringValidation(string& str) {
    bool isValid = false;

    while (!isValid) {
        bool containsOnlyLetters = true;

        // Check if the string contains only alphabetic characters
        for (const char ch : str) {
            if (!isalpha(ch)) {
                containsOnlyLetters = false;
                break;
            }
        }

        if (containsOnlyLetters) {
            isValid = true;
        } else {
            cout << "Invalid input. Please enter letters only: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> str;
        }
    }
}

int main() {
    string fname, lname;
    int month;
    bool validInput = false;

    while (!validInput) {
        cout << "What month of 2024 is this invoice for? (1-12): ";
        cin >> month;

        try {
            if (!cin) {
                throw invalid_argument("Invalid input. Please enter a number between 1 and 12.");
            }
            if (month < 1 || month > 12) {
                throw out_of_range("Month must be between 1 and 12.");
            }
            validInput = true;
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } catch (const invalid_argument& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Create a date object for the first day of the month
    date invoiceMonthFirstDay(month, 1, 2024);
    // Find out what day of the week the first day of the month is
    weekdayType invoiceFirstWeekday = firstWeekdayOfMonth2024[month];
    // Example: 2024-10-01 is Tuesday.
    cout << invoiceMonthFirstDay << " is " << weekdayToString(invoiceFirstWeekday) << ". " << endl;

    bool wantToExit = false;

    // Create a Recipient object (since Person is abstract)
    cout << "Who is this invoice for?" << endl;
    cout << "Enter recipient's first name: ";
    cin >> fname;
    stringValidation(fname);
    cout << "Enter recipient's last name: ";
    cin >> lname;
    stringValidation(lname);
    Recipient recipient(fname, lname);

    do {
        // Add a student
        cout << "Who takes lessons?" << endl;
        cout << "Enter student's first name: ";
        cin >> fname;
        stringValidation(fname);

        cout << "Enter student's last name: ";
        cin >> lname;
        stringValidation(lname);
        // Create a Student object
        Student student(fname, lname);

        char userChoice;
        do {
            // Add a lesson to the student
            int day, duration;
            float hourlyFee;

            cout << "Enter lesson details:" << endl;
            cout << "What day does " << student << "have a lesson?" << endl;
            cout << "(1 = Sunday, 2 = Monday, 3 = Tuesday, 4 = Wednesday, 5 = Thursday, 6 = Friday, 7 = Saturday ): ";
            cin >> day;
            while (!cin || day < 1 || day > 7) {
                cout << "Invalid input. Please enter a number between 1 and 7: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> day;
            }

            // This gets used to instantiate the lesson
            weekdayType lsWeekday = static_cast<weekdayType>(day);
            cout << "You entered: " << weekdayToString(lsWeekday) << endl;

            // Find the first lesson weekday. Will it be in the first week or the second week?
            int temp;
            vector<date> tempDateList;
            // If the weekday the lesson is on is before the first weekday of the month,
                // then the first lesson is on the following week
            if (lsWeekday < invoiceFirstWeekday) {
                // first lesson date
                temp = 1 + 7 - (invoiceFirstWeekday - lsWeekday);
            }
            // Otherwise, the first lesson is on the same week
            else
            {
                // first lesson date
                temp = 1 + lsWeekday - invoiceFirstWeekday;
            }
            // Create a list of dates for the lessons and count the lesson quantity
            int quantity = 0;
            // invoiceMonthFirstDay example 2024-10-01
            for (int i = temp; i <= invoiceMonthFirstDay.daysInMonth(month, 2024); i+=7) {
                date lessonDate(month, i, 2024);
                tempDateList.push_back(lessonDate);
                quantity++;
            }

            cout << "Enter lesson duration in minutes: ";
            // should be at least 30 minutes
            cin >> duration;
            // should be at least $30
            cout << "Enter hourly fee: ";
            cin >> hourlyFee;

            try {
                Lesson lesson(static_cast<weekdayType>(day), duration, hourlyFee, quantity, tempDateList);
                student.addLesson(lesson);  // Add the lesson to the student vector
                cout << "Lessons happen on ";
                lesson.printDateList();
            } catch (const invalid_argument& e) {
                cerr << "Error creating lesson: " << e.what() << endl;
                return 1;
            }

            // Ask if they want to add another lesson
            cout << "\nDo you want to add another lesson? (Y/N)";
            cin >> userChoice;
            while(!cin || (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n')) {
                cout << "Invalid input. Please enter Y or N: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> userChoice;
            }
        } while (userChoice != 'N' && userChoice != 'n');

        // Add the student to the recipient
        recipient.addStudent(student);

        cout << "\nDo you want to add another student? (Y/N)";
        cin >> userChoice;
        while(!cin || (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n')) {
            cout << "Invalid input. Please enter Y or N: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> userChoice;
        }
        if (userChoice == 'N' || userChoice == 'n') {
            wantToExit = true;
        }
    } while (!wantToExit);

    // Print details
    recipient.print();

    return 0;
}
