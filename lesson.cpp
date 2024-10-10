/* Program name: lesson.cpp
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: Create Lesson class
*/

#include "lesson.h"
#include <iostream>
#include <iomanip>

// Lesson constructor
Lesson::Lesson(weekdayType lsWeekday, int lsDuration, float hourlylsFee, int lsQty, vector<date> tempDateList)
    : lessonWeekday(lsWeekday), lessonDuration(lsDuration), hourlyLessonFee(hourlylsFee), lessonQty(lsQty), lessonDateList(tempDateList) {
        if (lsDuration < 30 || hourlylsFee < 30 || lsQty <= 0) {
            throw invalid_argument("Invalid lesson details provided.");
        }
    calculateUnitPrice();           // Calculate and set unitPrice
    calculateTotalLessonPrice();    // Calculate and set totalLessonPrice
}

// Calculate unit price
float Lesson::calculateUnitPrice() {
    unitPrice = (lessonDuration / 60.0f) * hourlyLessonFee;
    return unitPrice;
}

// Calculate total lesson price
float Lesson::calculateTotalLessonPrice() {
    totalLessonPrice = unitPrice * lessonQty;
    return totalLessonPrice;
}

// Getters
float Lesson::getTotalLessonPrice() const {
    return totalLessonPrice;
}

vector<date> Lesson::getLessonDateList() const {
    return lessonDateList;
}

// Print lesson details
void Lesson::print() const {
    cout << weekdayToString(lessonWeekday) << ", Duration: " << lessonDuration << " minutes, "
         << "Unit Price: $" << fixed << setprecision(2) << unitPrice << ", "
         << "Number of Lessons: " << lessonQty << ", "
         << "Lesson dates: ";
         printDateList();
         cout << "*Total Lesson Price: $" << totalLessonPrice << "\n";
}

void Lesson::printDateList() const {
    for (const auto& lessonDate : lessonDateList) {
        cout << lessonDate << " ";
    }
}
