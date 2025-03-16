#include <iostream>
using namespace std;

int main() {
    int a, at;
    cin >> a >> at; // Read the first pair of integers (a and at)

    int b, bt;
    cin >> b >> bt; // Read the second pair of integers (b and bt)

    int t1, t2;
    char colon; // To read the ':' character
    cin >> t1 >> colon >> t2; // Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"

    int st = t2 + (t1 - 5) * 60; // Calculate the start time in seconds
    int fin = st + at; // Calculate the finish time in seconds

    int now = 0; // Initialize the current time to zero
    int ans = 0; // Initialize the answer to zero

    // Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
    while (now < fin && now < 1140) {
        // If the next event starts after the current time, increment the answer
        if (now + bt > st) {
            ans++;
        }
        // Increment the current time by the duration of the next event
        now += b;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
