
#include<iostream>

int main() {
    // Declare variables to hold input values
    int a, b, c, x, y;

    // Read five integer values from user input
    std::cin >> a >> b >> c >> x >> y;

    // Double the value of c
    c *= 2;

    // Check if the sum of a and b is less than or equal to c
    if (a + b <= c) {
        // If true, calculate and print the total cost using x and y
        std::cout << a * x + b * y << std::endl;
    } else {
        // If the sum of a and b is greater than c, check the value of x against y
        if (x <= y) {
            // If x is less than or equal to y, check if b is less than or equal to c
            if (b <= c) {
                // If true, calculate and print the total cost considering c and the remaining b
                std::cout << c * x + (y - x) * b << std::endl;
            } else {
                // If b is greater than c, print the total cost using c and y
                std::cout << c * y << std::endl;
            }
        } else {
            // If x is greater than y, check if a is less than or equal to c
            if (a <= c) {
                // If true, calculate and print the total cost considering c and the remaining a
                std::cout << c * y + (x - y) * a << std::endl;
            } else {
                // If a is greater than c, print the total cost using c and x
                std::cout << c * x << std::endl;
            }
        }
    }

    // Return 0 to indicate successful execution
    return 0;
}
