#include <iostream>
using namespace std;

int main() {
    // Taking two integer inputs and assigning them to candeleIntere and b.
    int candeleIntere, b;
    cin >> candeleIntere >> b;

    // Initializing the sum variable s and the remainder variable restoSciolte to 0.
    long long s = 0; // Using long long to avoid overflow for large sums
    int restoSciolte = 0;

    // Starting a while loop that continues as long as candeleIntere is greater than 0 or restoSciolte is greater than or equal to b.
    while (candeleIntere > 0 || restoSciolte >= b) {
        // Updating candeleIntere by adding the integer division of restoSciolte by b.
        candeleIntere += restoSciolte / b;

        // Updating restoSciolte to be the remainder of the division of restoSciolte by b.
        restoSciolte %= b;

        // Adding candeleIntere to s.
        s += candeleIntere;

        // Updating restoSciolte by adding the remainder of candeleIntere divided by b.
        restoSciolte += candeleIntere % b;

        // Updating candeleIntere by performing integer division of candeleIntere by b.
        candeleIntere /= b;
    }

    // Printing the value of s after the loop completes.
    cout << s << endl;

    return 0;
}

// <END-OF-CODE>
