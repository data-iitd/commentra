#include <iostream>
#include <string>
#include <sstream>

int main() {
    int a, at;
    int b, bt;
    int t1, t2;

    std::cin >> a >> b;
    std::cin >> at >> bt;
    std::string time;
    std::cin >> time;

    // Extracting hours and minutes from the input string
    t1 = std::stoi(time.substr(0, 2));
    t2 = std::stoi(time.substr(3, 2));

    // Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
    int st = t2 + (t1 - 5) * 60;

    // Calculate the finish time by adding at to the start time
    int fin = st + at;

    // Initialize now and ans variables
    int now = 0;
    int ans = 0;

    // Loop until now is less than fin and now is less than 1140
    while (now < fin && now < 1140) {
        if (now + bt > st) {  // Check if adding bt to now would exceed the start time
            ans += 1;  // Increment ans if the condition is met
        }
        now += b;  // Increment now by b
    }

    // Print the final value of ans
    std::cout << ans << std::endl;

    return 0;
}
