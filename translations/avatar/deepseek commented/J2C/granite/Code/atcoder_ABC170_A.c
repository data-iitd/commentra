
#include <stdio.h>  // Including necessary header files

int main() {
    char input[100];  // Declaring an array to store the input
    int result = 0;  // Initializing a variable to store the count of non-zero elements

    // Reading input from the user and storing it in the array
    printf("Enter the input: ");
    fgets(input, sizeof(input), stdin);

    // Iterating through the array and updating the result
    for (int i = 0; input[i]!= '\0'; i++) {
        result++;  // Incrementing the result for each non-zero element
        if (input[i] == '0') break;  // Breaking the loop if a zero is encountered
    }

    printf("The count of non-zero elements is: %d\n", result);  // Printing the result to the console

    return 0;  // Returning 0 to indicate successful execution
}

