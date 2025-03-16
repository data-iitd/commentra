#include <iostream> // Include the iostream library for input/output
#include <sstream>  // Include the sstream library for string stream
#include <iomanip>  // Include the iomanip library for formatting
#include <chrono>   // Include the chrono library for time handling

using namespace std;

int main() {
    // Declare variables to hold the input time strings
    string time1, time2;

    // Read the first time string from the console
    cin >> time1;
    // Read the second time string from the console
    cin >> time2;

    // Split the first time string into hour and minute parts
    int hour1, minute1;
    char colon1;
    stringstream ss1(time1);
    ss1 >> hour1 >> colon1 >> minute1;

    // Split the second time string into hour and minute parts
    int hour2, minute2;
    char colon2;
    stringstream ss2(time2);
    ss2 >> hour2 >> colon2 >> minute2;

    // Create time points for the two times
    auto x = chrono::hours(hour1) + chrono::minutes(minute1);
    auto y = chrono::hours(hour2) + chrono::minutes(minute2);

    // Calculate the difference between the two times
    auto diff = x - y;

    // Convert the difference to hours and minutes
    auto hours = chrono::duration_cast<chrono::hours>(diff).count();
    auto minutes = chrono::duration_cast<chrono::minutes>(diff).count() % 60;

    // Print the result
    cout << hours << " hours and " << minutes << " minutes" << endl;

    return 0;
}

// <END-OF-CODE>
