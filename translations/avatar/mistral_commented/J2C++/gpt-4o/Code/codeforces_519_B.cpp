#include <iostream> // Importing I/O classes
#include <vector>   // Importing vector class

using namespace std;

int main() {
    // Main function is the entry point of the C++ application

    int n;
    cin >> n; // Reading the number of test cases (n) from the input

    int a = 0, b = 0, c = 0; // Declaring and initializing three integer variables a, b, and c with zero values

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp; // Reading the first number in each test case
        a += temp;   // Adding it to the variable 'a'
    }

    for (int i = 0; i < n - 1; i++) {
        int temp;
        cin >> temp; // Reading the second number in each test case (except the last one)
        b += temp;   // Adding it to the variable 'b'
    }

    for (int i = 0; i < n - 2; i++) {
        int temp;
        cin >> temp; // Reading the third number in each test case (except the last two)
        c += temp;   // Adding it to the variable 'c'
    }

    int x = a - b; // Calculating the difference between the sum of the first and second number in each test case
    int y = b - c; // Calculating the difference between the sum of the second and third number in each test case

    cout << x << endl; // Printing the value of 'x' to the standard output
    cout << y << endl; // Printing the value of 'y' to the standard output

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
