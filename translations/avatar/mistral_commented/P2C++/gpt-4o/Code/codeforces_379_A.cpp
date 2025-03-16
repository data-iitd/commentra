#include <iostream>
using namespace std;

int main() {
    // Get the number of candles 'candeleIntere' and the box size 'b' from user input
    int candeleIntere, b;
    cin >> candeleIntere >> b;

    // Initialize the sum 's' to 0
    int s = 0;

    // Initialize the remaining candles 'restoSciolte' to 0
    int restoSciolte = 0;

    // Continue the loop as long as there are still candles or the remaining candles are greater than or equal to the box size
    while (candeleIntere > 0 || restoSciolte >= b) {
        // Calculate the number of full boxes of candles that can be put in the box
        candeleIntere += restoSciolte / b;

        // Update the remaining candles
        restoSciolte %= b;

        // Add the number of candles in the current box to the sum
        s += candeleIntere;

        // Update the remaining candles by adding the remainder of the current box
        restoSciolte += candeleIntere % b;

        // Update the number of candles to be put in the next box
        candeleIntere /= b;
    }

    return 0;
}

// <END-OF-CODE>
