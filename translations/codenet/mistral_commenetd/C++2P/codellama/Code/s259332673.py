#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++) // Macro for repetition

using namespace std;

int main() // Main function
{
    int h1, h2, m1, m2, k; // Declare variables for hours and minutes of first and second time, and the difference
    
    // Input the values of hours and minutes for the first and second time
    cin >> h1 >> m1;
    cout << "Enter hours and minutes for the first time: ";
    cin >> h1 >> m1;

    cin >> h2 >> m2;
    cout << "Enter hours and minutes for the second time: ";
    cin >> h2 >> m2;

    int ans = h2 * 60 + m2; // Calculate the total minutes of the second time
    cout << "The total minutes of the second time are: " << ans << endl;

    ans -= (h1 * 60 + m1); // Subtract the total minutes of the first time from the total minutes of the second time
    cout << "The difference in minutes is: " << ans << endl;

    ans -= k; // Subtract the given difference 'k' from the difference in minutes
    cout << "The difference in minutes after subtracting " << k << " is: " << ans << endl;

    // Convert the difference in minutes to hours and minutes
    int hours = ans / 60;
    int minutes = ans % 60;

    cout << hours << " hours and " << minutes << " minutes" << endl; // Output the result

    return 0;
}

