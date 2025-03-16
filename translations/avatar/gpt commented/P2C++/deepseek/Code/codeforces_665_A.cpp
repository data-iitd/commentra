#include <iostream>
#include <string>
#include <sstream>

int main() {
    int a, at;
    int b, bt;
    int t1, t2;
    std::string time_input;
    std::getline(std::cin, time_input);
    std::stringstream ss(time_input);
    ss >> t1 >> t2;

    int st = t2 + (t1 - 5) * 60;  // Convert start time to minutes since 5:00

    std::cin >> a >> at;
    std::cin >> b >> bt;

    int fin = st + at;
    int now = 0;
    int ans = 0;

    while (now < fin && now < 1140) {
        if (now + bt > st) {
            ans++;
        }
        now += b;
    }

    std::cout << ans << std::endl;

    return 0;
}
