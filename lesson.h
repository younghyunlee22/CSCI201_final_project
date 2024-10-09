//
// Created by Younghyun Lee on 10/7/24.
//

#ifndef LESSON_H
#define LESSON_H

#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"

class Lesson {
public:
    // Constructor
    Lesson(weekdayType lsWeekday, int lsDuration, float hourlylsFee, int lsQty);

    // Getters
    float calculateUnitPrice();
    float calculateTotalLessonPrice();
    float getTotalLessonPrice() const;

    // Print lesson details
    void print() const;

private:
    weekdayType lessonWeekday;   // Day of the lesson
    int lessonDuration;          // Duration in minutes
    float hourlyLessonFee;       // Fee per hour
    int lessonQty;               // Number of lessons
    float unitPrice;             // Calculated unit price
    float totalLessonPrice;      // Calculated total price

    // Helper function to get weekday string
    string getWeekdayString(weekdayType day) const;
};

#endif //LESSON_H
