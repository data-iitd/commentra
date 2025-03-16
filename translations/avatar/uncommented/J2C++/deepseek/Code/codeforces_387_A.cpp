#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string s_hour, s_minute, t_hour, t_minute;
    std::getline(ss, s_hour, ':');
    std::getline(ss, s_minute, ':');
    std::getline(ss, t_hour, ':');
    std::getline(ss, t_minute, ':');

    int s_h = std::stoi(s_hour);
    int s_m = std::stoi(s_minute);
    int t_h = std::stoi(t_hour);
    int t_m = std::stoi(t_minute);

    int total_minutes_s = s_h * 60 + s_m;
    int total_minutes_t = t_h * 60 + t_m;

    int difference = total_minutes_s - total_minutes_t;

    if (difference < 0) {
        difference += 24 * 60;
    }

    int result_hour = difference / 60;
    int result_minute = difference % 60;

    std::cout << std::setw(2) << std::setfill('0') << result_hour << ":"
              << std::setw(2) << std::setfill('0') << result_minute << std::endl;

    return 0;
}
