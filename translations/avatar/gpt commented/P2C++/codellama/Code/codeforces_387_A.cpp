#include <iostream>
using namespace std;

int main()
{
    // Read the first time input in 'hh:mm' format and split it into hours and minutes
    int h1, m1;
    cin >> h1 >> m1;

    // Convert the first time into total minutes
    m1 += h1 * 60;

    // Read the second time input in 'hh:mm' format and split it into hours and minutes
    int h2, m2;
    cin >> h2 >> m2;

    // Convert the second time into total minutes
    m2 += h2 * 60;

    // Calculate the difference in minutes between the first and second time
    m2 = m1 - m2;

    // Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
    m2 %= 1440;

    // Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
    cout << setfill('0') << setw(2) << m2 / 60 << ":" << setfill('0') << setw(2) << m2 % 60 << endl;

    return 0;
}

