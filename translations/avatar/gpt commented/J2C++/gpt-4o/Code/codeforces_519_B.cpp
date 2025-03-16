#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a variable to hold the number of elements to be processed
    int n;
    cin >> n;

    // Initialize variables to hold the sums of three different sets of integers
    int a = 0, b = 0, c = 0;

    // Read n integers and calculate their sum (a)
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a += num;
    }

    // Read n-1 integers and calculate their sum (b)
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        b += num;
    }

    // Read n-2 integers and calculate their sum (c)
    for (int i = 0; i < n - 2; i++) {
        int num;
        cin >> num;
        c += num;
    }

    // Calculate the difference between the sums: x = sum of first set - sum of second set
    int x = a - b;

    // Calculate the difference between the sums: y = sum of second set - sum of third set
    int y = b - c;

    // Print the results of the differences
    cout << x << endl;
    cout << y << endl;

    return 0;
}

// <END-OF-CODE>
