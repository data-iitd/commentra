#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    std::string time1, time2;
    std::cin >> time1 >> time2;

    // Split the times by colon
    std::stringstream ss1(time1);
    std::stringstream ss2(time2);
    int hour1, minute1, hour2, minute2;
    char colon;
    ss1 >> hour1 >> colon >> minute1;
    ss2 >> hour2 >> colon >> minute2;

    // Convert to LocalTime objects
    // Assuming LocalTime is a custom struct or class that holds hours and minutes
    // For simplicity, we'll use std::tm and std::time_t to represent time
    std::tm t1 = {0, minute1, hour1, 0, 0, 0, 0, 0, 0};
    std::tm t2 = {0, minute2, hour2, 0, 0, 0, 0, 0, 0};
    std::time_t time1_t = std::mktime(&t1);
    std::time_t time2_t = std::mktime(&t2);

    // Step 2: Calculate the difference between the two times
    double diff = std::difftime(time1_t, time2_t);
    int hours_diff = static_cast<int>(diff) / 3600;
    int minutes_diff = (static_cast<int>(diff) % 3600) / 60;

    // Output the difference
    std::cout << hours_diff << " hours " << minutes_diff << " minutes" << std::endl;

    return 0;
}
