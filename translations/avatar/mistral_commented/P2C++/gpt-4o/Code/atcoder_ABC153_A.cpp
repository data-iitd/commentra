#include <iostream>
using namespace std;

int main() {
    int h, a;
    cin >> h >> a; // Assign the first and second elements of the input to variables h and a

    int sho = h / a; // Calculate the quotient of h by a
    int am = h % a;  // Calculate the remainder of the division of h by a

    if (am != 0) {   // Check if the remainder is equal to zero
        sho += 1;    // Increment the value of sho by one
    }

    cout << sho;     // Print the value of sho
    return 0;
}

// <END-OF-CODE>
