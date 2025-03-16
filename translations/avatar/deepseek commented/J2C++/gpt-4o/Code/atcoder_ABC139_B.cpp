#include <iostream>
#include <iomanip>

int main() {
    // Step 1: Create a variable to read input from the standard input stream.
    int A, B;

    // Step 2: Read the first integer A from the input.
    std::cin >> A;

    // Step 3: Read the second integer B from the input.
    std::cin >> B;

    // Step 4: Initialize variables to store the quotient and remainder.
    int amari = 0;
    int result = 0;

    // Step 5: Calculate the quotient (result) by dividing (B-1) by (A-1).
    result = (B - 1) / (A - 1);

    // Step 6: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
    amari = (B - 1) % (A - 1);

    // Step 7: If the remainder is not zero, increment the result by 1.
    if (amari != 0) {
        result += 1;
    }

    // Step 8: Print the result to the standard output.
    std::cout << result << std::endl;

    return 0; // Step 9: Return 0 to indicate successful completion.
}

// <END-OF-CODE>
