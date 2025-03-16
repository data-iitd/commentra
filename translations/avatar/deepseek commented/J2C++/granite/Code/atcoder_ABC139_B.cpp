

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    // Step 1: Create a Scanner object to read input from the standard input stream.
    int A, B;
    cin >> A >> B;

    // Step 2: Initialize variables to store the quotient and remainder.
    int amari = 0;
    int result = 0;

    // Step 3: Calculate the quotient (result) by dividing (B-1) by (A-1).
    result = (B - 1) / (A - 1);

    // Step 4: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
    amari = (B - 1) % (A - 1);

    // Step 5: If the remainder is not zero, increment the result by 1.
    if (amari!= 0) {
        result += 1;
    }

    // Step 6: Create a PrintWriter object to write output to the standard output stream.
    printf("%d\n", result);

    // Step 7: Close the Scanner object to free up resources.
    //cin.close();

    // Step 8: Flush the PrintWriter to ensure all output is written to the output stream.
    //out.flush();

    return 0;
}
