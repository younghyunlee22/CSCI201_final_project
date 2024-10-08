//
// Created by Younghyun Lee on 10/7/24.
//

#include <iostream>
#include "person.h"
#include "lesson.h"
// #include "date.h"
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, weekdayType> firstWeekdayOfMonth {
                {10, TUESDAY},
                {11, FRIDAY},
                {12, SUNDAY}
};

int main() {

    int month;
    cout << "What month of 2024 is this invoice for? Type in number: " << endl;
    cin >> month;

    date monthObj(month, 1, 2024);
    weekdayType fstWeekdayOfMth = firstWeekdayOfMonth[month];
    cout << monthObj << " is " << weekdayToString(fstWeekdayOfMth) << endl;

    int lessonDayChoice;
    cout << "What weekday does this student take class? Type in number: " << endl;
    cout << "Sunday: 1, Monday: 2, Tuesday: 3, Wednesday: 4, Thursday: 5, Friday: 6, Saturday: 7" << endl;
    cin >> lessonDayChoice;

    weekdayType lessonDay = static_cast<weekdayType>(lessonDayChoice-1);
    cout << "The student takes class on " << weekdayToString(lessonDay) << endl;

    // vector<date> lessonDates;
    // for (int i = 1; i <monthObj.daysInMonth(month, 2024); i += 7) {
    //     lessonDates.push_back(date(month, i, 2024));
    // }
    //
    // cout << "lessonDates contains:";
    // for (date& x : lessonDates) {
    //     cout << ' ' << x;
    // }

    return 0;
}

