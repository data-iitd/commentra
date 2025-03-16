#include <iostream> // Importing required C++ header for input/output streams
#include <vector>   // Importing required C++ header for using vectors
#include <string>   // Importing required C++ header for using strings

using namespace std;

int main() {
    int n; // Declaring an integer variable 'n' to store the number of test cases

    // Reading the first line of input which contains the number of test cases
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading the integer

    // Checking if the number of test cases is equal to 1
    if (n == 1) {
        // If yes, printing "Hello World" as output
        cout << "Hello World" << endl;
    } else {
        // If not, reading the next two lines of input which contain two integers
        int num1, num2;
        cin >> num1 >> num2; // Storing the two integers

        // Printing the sum of the two integers as output
        cout << (num1 + num2) << endl;
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
