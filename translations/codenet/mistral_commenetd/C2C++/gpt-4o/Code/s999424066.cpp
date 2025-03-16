#include <iostream> // Include the iostream library for input/output

int main() { // Start of the main function
    int a, b, c, x, y; // Declare variables a, b, c, x, and y as integers
    std::cin >> a >> b >> c >> x >> y; // Read five integers from the standard input and store them in variables a, b, c, x, and y

    c *= 2; // Multiply the value of variable c by 2

    if (a + b <= c) { // Check if the sum of variables a and b is less than or equal to the value of variable c
        std::cout << a * x + b * y << std::endl; // If the condition is true, print the result of multiplying variables a and x, and variables b and y, and then print a newline character
    } else { // If the condition in the if statement is false, execute the code in the else block

        if (x <= y) { // Check if the value of variable x is less than or equal to the value of variable y

            if (b <= c) { // Check if the value of variable b is less than or equal to the value of variable c
                std::cout << c * x + (y - x) * b << std::endl; // If both conditions in the nested if statement are true, print the result of multiplying variable c by x, and then subtract the value of x from y and multiply the result by b, and finally print a newline character
            } else { // If the first condition in the nested if statement is false, execute the code in this else block
                std::cout << c * y << std::endl; // Print the result of multiplying variable c by the value of variable y, and then print a newline character
            }

        } else { // If the condition in the outer if statement is false and the condition in the if statement that checks if x is less than or equal to y is also false, execute the code in this else block

            if (a <= c) { // Check if the value of variable a is less than or equal to the value of variable c
                std::cout << c * y + (x - y) * a << std::endl; // If the condition is true, print the result of multiplying variable c by the value of y, subtract the value of y from x, and then multiply the result by a, and finally print a newline character
            } else { // If the condition in the if statement that checks if a is less than or equal to c is false, execute the code in this else block
                std::cout << c * x << std::endl; // Print the result of multiplying variable c by the value of x, and then print a newline character
            }

        } // End of the else statement that checks if x is greater than y

    } // End of the else statement that checks if the sum of a and b is greater than c

    return 0; // Indicate that the main function has ended successfully
} // End of the main function
// <END-OF-CODE>
