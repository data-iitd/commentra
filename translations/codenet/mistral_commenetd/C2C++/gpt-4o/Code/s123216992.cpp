#include <iostream>
// Include the iostream library for input/output

void swap(int *a, int *b) {
    // Function to swap two integers passed by reference
    int tmp;
    // Declare a temporary variable to store the value of 'a'

    tmp = *a;
    // Assign the value of 'b' to 'a'

    *a = *b;
    // Assign the value of 'a' to 'b'

    *b = tmp;
    // Assign the value of the temporary variable 'tmp' back to 'b'
}

int main() {
    // Declare two integer variables 'a' and 'b'
    int a, b;

    while (true) {
        // Infinite loop to read two integers from the user

        std::cin >> a >> b;
        // Read two integers from the user and store them in 'a' and 'b' respectively

        if (a == 0 && b == 0) break;
        // If both 'a' and 'b' are zero, break out of the loop

        if (b < a) swap(&a, &b);
        // If 'b' is less than 'a', swap their values

        std::cout << a << " " << b << std::endl;
        // Print the swapped values of 'a' and 'b'
    }
    // Return 0 to indicate successful execution of the program

    return 0;
}

// <END-OF-CODE>
