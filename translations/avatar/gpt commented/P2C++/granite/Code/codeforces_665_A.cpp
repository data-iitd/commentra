
#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, at, b, bt, t1, t2, st, fin, now, ans;
    string s;

    // Read the starting time and duration of activity A
    cin >> a >> at;

    // Read the starting time and duration of activity B
    cin >> b >> bt;

    // Read the start time in hours and minutes, then convert it to total minutes
    cin >> s;
    t1 = (s[0] - '0') * 10 + (s[1] - '0');
    t2 = (s[3] - '0') * 10 + (s[4] - '0');
    st = t2 + (t1 - 5) * 60;  // Convert start time to minutes since 5:00

    // Calculate the finish time for activity A
    fin = st + at;

    // Initialize the current time and the answer counter
    now = 0;
    ans = 0;

    // Loop until the current time exceeds the finish time or the maximum time limit (19:00 or 1140 minutes)
    while (now < fin && now < 1140) {
        // Check if activity B can start after the current time
        if (now + bt > st) {
            ans++;  // Increment the count of possible starts for activity B
        }
        now += b;  // Move the current time forward by the duration of activity B
    }

    // Print the total number of times activity B can start
    cout << ans << endl;

    return 0;
}
