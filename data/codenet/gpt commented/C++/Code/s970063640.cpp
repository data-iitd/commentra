#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Declare an integer to hold the number of elements
    int n;
    // Read the number of elements from user input
    cin >> n;

    // Declare an integer to hold the number of largest elements to sum
    int a;
    // Read the number of largest elements to sum from user input
    cin >> a;

    // Initialize a variable to hold the sum of the largest elements
    int sum = 0;

    // Declare an array to hold the elements
    int s[n];

    // Read the elements into the array from user input
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // Sort the array in non-decreasing order
    sort(s, s + n);

    // Sum the largest 'a' elements from the sorted array
    for (int i = n - 1; i > n - a - 1; i--) {
        sum += s[i];
    }

    // Output the calculated sum of the largest 'a' elements
    cout << sum << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
