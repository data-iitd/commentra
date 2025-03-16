#include <iostream>  // Step 1: Include the iostream library for input/output.

int main() {  // Step 2: Define the main function.
    char m;  // Step 3: Declare a character variable 'm'.
    int a, b, c[256], i;  // Declare two integers 'a' and 'b', an array 'c' of size 256, and an integer variable 'i'.

    for (i = 0; i < 256; i++) {  // Step 4: Start a loop with a condition to prevent overflow.
        std::cin >> a >> m >> b;  // Step 5: Read three inputs: an integer 'a', a character 'm', and an integer 'b'.
        if (m == '?') {  // Step 6: Check if the character 'm' is '?'. If true, break the loop.
            break;
        }
        if (m == '+') {  // Step 7: Depending on the character 'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
            c[i] = a + b;
        }
        if (m == '-') {
            c[i] = a - b;
        }
        if (m == '*') {
            c[i] = a * b;
        }
        if (m == '/') {
            c[i] = a / b;
        }
        i++;  // Increment 'i' after processing the input.
    }

    for (int j = 0; j < i; j++) {  // Step 9: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
        std::cout << c[j] << std::endl;
    }
    return 0;  // Step 10: Return 0 to indicate successful execution.
}  // <END-OF-CODE>
