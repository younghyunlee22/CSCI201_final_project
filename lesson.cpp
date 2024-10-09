//
// Created by Younghyun Lee on 10/7/24.
//

#include "lesson.h"

// Lesson constructor
Lesson::Lesson(weekdayType lsWeekday, int lsDuration, float hourlylsFee, int lsQty)
    : lessonWeekday(lsWeekday), lessonDuration(lsDuration), hourlyLessonFee(hourlylsFee), lessonQty(lsQty) {
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

float Lesson::getTotalLessonPrice() const {
    return totalLessonPrice;
}

// Print lesson details
void Lesson::print() const {
    cout << "Lesson: " << getWeekdayString(lessonWeekday) << ", Duration: " << lessonDuration << " minutes, "
         << "Unit Price: $" << fixed << setprecision(2) << unitPrice << ", "
         << "Number of Lessons: " << lessonQty << " "
         << "Total Lesson Price: $" << totalLessonPrice << "\n";
}

// Helper function to convert weekdayType to string
string Lesson::getWeekdayString(weekdayType day) const {
    switch (day) {
        case SUNDAY: return "Sunday";
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        default: return "Unknown";
    }
}
