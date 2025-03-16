#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::string time1, time2;
    std::cin >> time1 >> time2;

    // Split the time strings into hour and minute parts
    std::stringstream ss1(time1);
    std::stringstream ss2(time2);
    int hour1, minute1, hour2, minute2;
    char colon;
    ss1 >> hour1 >> colon >> minute1;
    ss2 >> hour2 >> colon >> minute2;

    // Calculate the difference in hours and minutes
    int diff_hour = hour1 - hour2;
    int diff_minute = minute1 - minute2;

    // Handle negative minutes
    if (diff_minute < 0) {
        diff_hour -= 1;
        diff_minute += 60;
    }

    // Handle negative hours
    if (diff_hour < 0) {
        diff_hour += 24;
    }

    // Output the result
    std::cout << std::setw(2) << std::setfill('0') << diff_hour << ":"
              << std::setw(2) << std::setfill('0') << diff_minute << std::endl;

    return 0;
}
