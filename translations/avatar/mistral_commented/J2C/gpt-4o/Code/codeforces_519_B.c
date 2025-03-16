#include <stdio.h>  // Including standard input/output library

int main() {
    // Main function is the entry point of the C application

    int n;
    scanf("%d", &n);
    // Reading the number of test cases (n) from the input using scanf

    int a = 0, b = 0, c = 0;
    // Declaring and initializing three integer variables a, b, and c with zero values

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        a += temp;
    }
    // Using a for loop to read and sum up the first number in each test case and adding it to the variable 'a'

    for (int i = 0; i < n - 1; i++) {
        int temp;
        scanf("%d", &temp);
        b += temp;
    }
    // Using a for loop to read and sum up the second number in each test case (except the last one) and adding it to the variable 'b'

    for (int i = 0; i < n - 2; i++) {
        int temp;
        scanf("%d", &temp);
        c += temp;
    }
    // Using a for loop to read and sum up the third number in each test case (except the last two) and adding it to the variable 'c'

    int x = a - b;
    // Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

    int y = b - c;
    // Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

    printf("%d\n", x);
    printf("%d\n", y);
    // Printing the values of 'x' and 'y' to the standard output using printf

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
