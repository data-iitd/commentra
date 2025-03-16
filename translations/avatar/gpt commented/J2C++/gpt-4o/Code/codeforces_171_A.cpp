#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// FastReader class to handle fast input
class FastReader {
public:
    // Method to read the next integer from input
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    // Method to read the next line from input
    string nextLine() {
        string str;
        cin.ignore(); // Ignore the newline character left in the buffer
        getline(cin, str);
        return str;
    }
};

// Function to reverse the digits of an integer n
int reverse(int n) {
    // If n is a single digit, return n multiplied by 10
    if (n < 10) return n * 10;

    int t = n, r = 0;

    // Loop to reverse the digits of n
    while (t > 0) {
        r = (r * 10) + t % 10; // Add the last digit of t to r
        t = t / 10; // Remove the last digit from t
    }

    // Return the reversed integer
    return r;
}

int main() {
    // Create an instance of FastReader for input
    FastReader sc;

    // Read two integers n and m from input
    int n = sc.nextInt();
    int m = sc.nextInt();

    // Reverse the integer m and store the result in t
    int t = reverse(m);

    // Print the sum of t and n
    cout << (t + n) << endl;

    return 0;
}

// <END-OF-CODE>
