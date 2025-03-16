#include <iostream> // Include iostream for input/output operations
#include <cstring>  // Include cstring for string manipulation functions

int main() // Function definition for main function
{
    int i; // Initialize integer variable 'i'
    int sum = 0; // Initialize integer variable 'sum' to zero
    char x[1002]; // Initialize character array 'x' of size 1002

    // Read a string from standard input and store it in 'x' array
    std::cout << "Enter a string of digits separated by spaces or newline: ";
    std::cin >> x;

    do { // Begin a do-while loop

        // Initialize sum to zero before processing each string
        sum = 0;

        // Process each character in the string 'x'
        for (i = 0; i < 1002; i++) {
            // Check if current character is end-of-string marker
            if (x[i] == 0) {
                // If so, print the sum of digits in the previous string and exit the loop
                std::cout << "Sum of digits in previous string: " << sum << std::endl;
                break;
            } else {
                // Otherwise, add the ASCII value of the character to the sum (subtracting 0x30 to convert ASCII to integer)
                sum += x[i] - '0';
            }
        }

        // Read next string from standard input
        std::cout << "Enter a string of digits separated by spaces or newline: ";
        std::cin >> x;

    } while (x[0] != '0'); // Continue the loop until the first character of the input string is '0'

    return 0; // Function returns 0 upon successful execution
}

// <END-OF-CODE>
