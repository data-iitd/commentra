#include <iostream>
using namespace std;

int main() {
    int n;  // Declare an integer variable to store the user input
    cin >> n;  // Taking an integer input from the user
    long long factorial = 1;  // Initializing a variable to store the factorial result

    for (int i = 1; i <= n; i++) {  // Starting a loop from 1 to the input number (inclusive)
        factorial *= i;  // Multiplying the factorial by the current number
    }

    cout << factorial << endl;  // Printing the factorial result
    return 0;  // Indicating that the program ended successfully
}

// <END-OF-CODE>
