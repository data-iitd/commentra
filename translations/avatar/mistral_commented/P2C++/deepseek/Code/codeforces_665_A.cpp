#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int a, at;
    int b, bt;
    string t1, t2;

    cin >> a >> at;
    cin >> b >> bt;
    cin >> t1 >> t2;

    // Convert time strings to integers
    int hour1 = stoi(t1.substr(0, 2));
    int minute1 = stoi(t1.substr(3, 2));
    int hour2 = stoi(t2.substr(0, 2));
    int minute2 = stoi(t2.substr(3, 2));

    // Calculate the start time in seconds
    int st = (hour2 * 60 + minute2) + (hour1 * 60 + minute1 - 5) * 60;

    // Calculate the finish time in seconds
    int fin = st + at;

    // Initialize the current time to zero
    int now = 0;
    int ans = 0;

    // Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
    while (now < fin && now < 1140) {
        // If the next event starts after the current time, increment the answer
        if (now + bt > st) {
            ans += 1;
        }
        // Increment the current time by the duration of the next event
        now += b;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
