#include <iostream>  // Step 1: Include the iostream library for input/output.

using namespace std;  // Step 2: Use the standard namespace.

void swap(int *a, int *b) {  // Step 3: Define a function named 'swap' that takes two integer pointers as arguments.
    int tmp;  // Step 4: Inside the 'swap' function, declare a temporary variable 'tmp'.
    tmp = *a;  // Step 5: Assign the value pointed to by 'a' to 'tmp'.
    *a = *b;  // Step 6: Assign the value pointed to by 'b' to the memory location pointed to by 'a'.
    *b = tmp;  // Step 7: Assign the value stored in 'tmp' to the memory location pointed to by 'b'.
}

int main() {  // Step 8: In the 'main' function, declare two integer variables 'a' and 'b'.
    while (true) {  // Step 9: Create an infinite loop using 'while(true)'.
        int a, b;
        cin >> a >> b;  // Step 10: Use 'cin' to read two integers from the user and store them in 'a' and 'b'.
        if (a == 0 && b == 0) break;  // Step 11: Check if both 'a' and 'b' are zero. If true, break the loop.
        if (b < a) swap(&a, &b);  // Step 12: Check if 'b' is less than 'a'. If true, call the 'swap' function to swap the values of 'a' and 'b'.
        cout << a << " " << b << endl;  // Step 13: Print the values of 'a' and 'b'.
    }
    return 0;  // Step 14: End the 'main' function with 'return 0'.
}

// <END-OF-CODE>
