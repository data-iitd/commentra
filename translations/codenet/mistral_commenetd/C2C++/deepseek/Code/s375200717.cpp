#include <iostream> // Including the standard input/output stream library

int main() { // The entry point of the program
    int n, i, a; // Declaring variables n, i, and a

    std::cin >> n; // Reading an integer value from the user and storing it in variable n

    for (i = 1; i <= n; i++) { // Starting a for loop that runs from 1 to n
        a = i; // Assigning the value of i to variable a

        if (a % 3 == 0) { // Checking if the value of a is divisible by 3
            std::cout << " " << i; // If true, print the value of i to the console
        } else { // If the condition is false
            for (; a; ) { // Starting an inner for loop that runs as long as a is not equal to 0
                if (a % 10 == 3) { // Checking if the last digit of the number stored in a is 3
                    std::cout << " " << i; // If true, print the value of i to the console
                    a = 0; // Setting a to 0 to break out of the inner for loop
                }
                a = a / 10; // Otherwise, moving to the next digit by dividing a by 10
            }
        }
    }
    std::cout << std::endl; // Printing a newline character to move the cursor to the next line
    return 0; // Indicating successful execution of the program
}
