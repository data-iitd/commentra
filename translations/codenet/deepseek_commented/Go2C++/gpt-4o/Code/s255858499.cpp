#include <iostream> // Importing the iostream library for input and output
#include <string>   // Importing the string library for string operations

using namespace std;

// Function to read an integer from input
int readInteger() {
    int num;
    cin >> num;
    return num;
}

int main() {
    // Reading the first integer input
    int a = readInteger();
    // Reading the second integer input
    int b = readInteger();

    // Checking if the product of a and b is odd or even and printing the result
    if (a * b % 2 != 0) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }

    return 0;
}

// <END-OF-CODE>
