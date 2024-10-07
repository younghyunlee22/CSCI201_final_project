//
// Created by Younghyun Lee on 10/7/24.
//

#include <iostream>
#include "person.h"
#include "lesson.h"
#include "date.h"
#include <unordered_map>

using namespace std;

enum weekdayType {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

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

unordered_map<int, weekdayType> firstWeekdayOfMonth {
    {10, TUESDAY},
    {11, FRIDAY},
    {12, SUNDAY}
};

int main() {

    int month;
    cout << "What month of 2024 is this invoice for? Type in number: " << endl;
    cin >> month;

    date oct(month, 1, 2024);
    weekdayType fstWeekdayOfMth = firstWeekdayOfMonth[month];
    cout << oct << " " << weekdayToString(fstWeekdayOfMth) << endl;
    return 0;
}

