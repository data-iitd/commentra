#include <iostream> // Including iostream for input/output
#include <sstream>  // Including sstream for string stream
#include <iomanip>  // Including iomanip for formatting
#include <chrono>   // Including chrono for time handling

using namespace std;

int main() {
    string s, t; // Strings to hold the time inputs
    cin >> s >> t; // Reading two time inputs in "HH:MM" format

    // Splitting the first time input into hours and minutes
    int s_hour, s_minute;
    char colon; // To consume the ':' character
    stringstream ss1(s);
    ss1 >> s_hour >> colon >> s_minute;

    // Splitting the second time input into hours and minutes
    int t_hour, t_minute;
    stringstream ss2(t);
    ss2 >> t_hour >> colon >> t_minute;

    // Creating time points for the two times
    auto x = chrono::hours(s_hour) + chrono::minutes(s_minute);
    auto y = chrono::hours(t_hour) + chrono::minutes(t_minute);

    // Calculating the difference between the two times
    auto diff = x - y;

    // Converting the difference to hours and minutes
    auto hours = chrono::duration_cast<chrono::hours>(diff);
    auto minutes = chrono::duration_cast<chrono::minutes>(diff) - hours;

    // Printing the result
    cout << hours.count() << " hours and " << minutes.count() << " minutes" << endl;

    return 0;
}

// <END-OF-CODE>
