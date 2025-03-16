#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare a variable to hold the number of submissions
    int n;
    // Read the number of submissions from the user
    cin >> n;

    // Initialize counters for different result types
    int ac_count = 0; // Count of Accepted submissions
    int wa_count = 0; // Count of Wrong Answer submissions
    int tle_count = 0; // Count of Time Limit Exceeded submissions
    int re_count = 0; // Count of Runtime Error submissions

    // Loop through each submission
    for (int i = 0; i < n; ++i) {
        string s; // Variable to hold the result of the current submission
        // Read the result of the current submission
        cin >> s;

        // Increment the respective counter based on the result
        if (s == "AC") {
            ac_count += 1; // Increment Accepted count
        } else if (s == "WA") {
            wa_count += 1; // Increment Wrong Answer count
        } else if (s == "TLE") {
            tle_count += 1; // Increment Time Limit Exceeded count
        } else if (s == "RE") {
            re_count += 1; // Increment Runtime Error count
        }
    }

    // Output the counts of each result type
    cout << "AC x " << ac_count << endl; // Display Accepted count
    cout << "WA x " << wa_count << endl; // Display Wrong Answer count
    cout << "TLE x " << tle_count << endl; // Display Time Limit Exceeded count
    cout << "RE x " << re_count << endl; // Display Runtime Error count
}
