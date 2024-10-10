/* Program name: Common.cpp
* Author: Younghyun Lee
* Date last updated: 10/9/2024
* Purpose: Common functions
*/

#include "common.h"
#include <string>

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

