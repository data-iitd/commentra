#include<iostream>

using namespace std;

int main() {
    // Declare an integer variable to store user input
    int n;

    // Read an integer value from the user
    cin >> n;

    // Check if the number is even
    if (n % 2 == 0) {
        // If the number is even, print half of the number
        cout << n / 2 << endl;
    } else {
        // If the number is odd, print half of the number plus one
        cout << (n / 2) + 1 << endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
