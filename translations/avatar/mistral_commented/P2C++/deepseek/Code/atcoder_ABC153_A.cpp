#include <iostream>
using namespace std;

int main() {
    int h, a;
    cin >> h >> a;
    // Read two integers from standard input and assign them to variables h and a, respectively

    int sho = h / a;
    // Calculate the quotient of h by a and assign the result to the variable sho

    int am = h % a;
    // Calculate the remainder of the division of h by a and assign the result to the variable am

    if (am != 0) {
    // Check if the remainder is equal to zero
    // If not, execute the following block of code

        sho += 1;
        // Increment the value of the variable sho by one
    }

    cout << sho << endl;
    // Print the value of the variable sho

    return 0;
}

