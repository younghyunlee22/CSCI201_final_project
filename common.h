/* Program name: Common.h
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: Common header file
*/

#ifndef COMMON_H
#define COMMON_H

#pragma once

#include <string>
using namespace std;

enum weekdayType {
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

string weekdayToString(weekdayType day);

#endif //COMMON_H
