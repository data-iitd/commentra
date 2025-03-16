#include <iostream>
using namespace std;

int main() {
    // Prompt the user to input their age
    int age;
    cin >> age;

    // Check if the age is equal to 1
    if (age == 1) {
        // If age is 1, print 'Hello World'
        cout << "Hello World" << endl;
    } else {
        // If age is not 1, prompt the user to input two integers
        int a, b;
        cin >> a >> b;
        // Calculate and print the sum of the two integers
        cout << (a + b) << endl;
    }

    return 0;
}

// <END-OF-CODE>
