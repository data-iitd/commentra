#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read the first time input in 'hh:mm' format and split it into hours and minutes
    string time1;
    cin >> time1;
    int h1 = stoi(time1.substr(0, 2));
    int m1 = stoi(time1.substr(3, 2));

    // Convert the first time into total minutes
    int m1_total = h1 * 60 + m1;

    // Read the second time input in 'hh:mm' format and split it into hours and minutes
    string time2;
    cin >> time2;
    int h2 = stoi(time2.substr(0, 2));
    int m2 = stoi(time2.substr(3, 2));

    // Convert the second time into total minutes
    int m2_total = h2 * 60 + m2;

    // Calculate the difference in minutes between the first and second time
    int m2_diff = m1_total - m2_total;

    // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
    m2_diff %= 1440;

    // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
    cout << setfill('0') << setw(2) << m2_diff / 60 << ":" << setw(2) << m2_diff % 60 << endl;

    return 0;
}

