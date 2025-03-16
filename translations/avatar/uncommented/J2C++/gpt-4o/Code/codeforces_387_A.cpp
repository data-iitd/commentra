#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int s_hour, s_minute, t_hour, t_minute;
    char colon;

    // Parse the first time
    stringstream ss1(s);
    ss1 >> s_hour >> colon >> s_minute;

    // Parse the second time
    stringstream ss2(t);
    ss2 >> t_hour >> colon >> t_minute;

    // Create time points
    auto x = chrono::hours(s_hour) + chrono::minutes(s_minute);
    auto y = chrono::hours(t_hour) + chrono::minutes(t_minute);

    // Calculate the difference
    auto result = x - y;

    // Convert the result back to hours and minutes
    auto hours = chrono::duration_cast<chrono::hours>(result);
    auto minutes = chrono::duration_cast<chrono::minutes>(result) - hours;

    cout << hours.count() << ":" << setw(2) << setfill('0') << minutes.count() << endl;

    return 0;
}

// <END-OF-CODE>
