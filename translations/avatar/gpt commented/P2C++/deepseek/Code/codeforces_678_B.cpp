#include <iostream>
using namespace std;

string leapyear(int n) {
    // Determine if the given year n is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return "y";  // Return 'y' if it is a leap year
    } else {
        return "n";  // Return 'n' if it is not a leap year
    }
}

int main() {
    int n;
    string d = "f";
    string ans;

    // Read an integer input from the user representing the year
    cin >> n;

    // Check if the initial year n is a leap year and set the answer accordingly
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        ans = "ly";  // 'ly' indicates leap year
    } else {
        ans = "nly";  // 'nly' indicates non-leap year
    }

    // Infinite loop to determine the next occurrence of a specific day
    while (true) {
        // If the current year n is a leap year
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            // Update the day variable and increment the year based on the current day
            if (d == "m") {
                d = "w";  // Monday to Wednesday
                n++;
            } else if (d == "t") {
                d = "th";  // Tuesday to Thursday
                n++;
            } else if (d == "w") {
                d = "f";  // Wednesday to Friday
                n++;
            } else if (d == "th") {
                d = "sa";  // Thursday to Saturday
                n++;
            } else if (d == "f") {
                d = "s";  // Friday to Sunday
                n++;
            } else if (d == "sa") {
                d = "m";  // Saturday to Monday
                n++;
            } else if (d == "s") {
                d = "t";  // Sunday to Tuesday
                n++;
            }
        } else {
            // If the current year n is not a leap year, update the day variable accordingly
            if (d == "m") {
                d = "t";  // Monday to Tuesday
                n++;
            } else if (d == "t") {
                d = "w";  // Tuesday to Wednesday
                n++;
            } else if (d == "w") {
                d = "th";  // Wednesday to Thursday
                n++;
            } else if (d == "th") {
                d = "f";  // Thursday to Friday
                n++;
            } else if (d == "f") {
                d = "sa";  // Friday to Saturday
                n++;
            } else if (d == "sa") {
                d = "s";  // Saturday to Sunday
                n++;
            } else if (d == "s") {
                d = "m";  // Sunday to Monday
                n++;
            }
        }

        // Check if we have reached a Friday and the leap year condition matches the answer
        if (d == "f" && ans == "ly" && leapyear(n) == "y") {
            break;  // Exit the loop if it's a leap year and it's Friday
        } else if (d == "f" && ans == "nly" && leapyear(n) == "n") {
            break;  // Exit the loop if it's not a leap year and it's Friday
        }
    }

    // Print the resulting year
    cout << n << endl;

    return 0;
}
