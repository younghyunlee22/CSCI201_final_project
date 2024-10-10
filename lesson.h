/* Program name: lesson.h
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: Create Lesson class
*/

#ifndef LESSON_H
#define LESSON_H

#include <vector>
#include "date.h"
#include "common.h"

class Lesson {
public:
    // Constructor
    Lesson(weekdayType lsWeekday, int lsDuration, float hourlylsFee, int lsQty, vector<date> tempDateList);

    // Getters
    float calculateUnitPrice();
    float calculateTotalLessonPrice();
    float getTotalLessonPrice() const;

    vector<date> getLessonDateList() const;

    // Print lesson details
    void print() const;
    void printDateList() const;

private:
    weekdayType lessonWeekday;   // Day of the lesson
    int lessonDuration;          // Duration in minutes
    float hourlyLessonFee;       // Fee per hour
    int lessonQty;               // Number of lessons
    float unitPrice;             // Calculated unit price
    float totalLessonPrice;      // Calculated total price
    vector<date> lessonDateList; // List of lesson dates
};

#endif //LESSON_H
