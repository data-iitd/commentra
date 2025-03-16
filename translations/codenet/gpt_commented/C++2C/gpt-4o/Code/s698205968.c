#include <stdio.h>

int main() {
    // Declare variables to hold marks for midterm, final, and retake
    int m, f, r;

    // Continuously read input until the termination condition is met
    while (scanf("%d %d %d", &m, &f, &r) == 3 && (m != -1 || f != -1 || r != -1)) {
        // Check if either midterm or final score is -1, indicating failure
        if (m == -1 || f == -1) 
            printf("F"); // Output "F" for failure
        // Check if the total score is 80 or more for grade A
        else if (m + f >= 80) 
            printf("A"); // Output "A" for excellent performance
        // Check if the total score is between 65 and 79 for grade B
        else if (m + f >= 65) 
            printf("B"); // Output "B" for good performance
        // Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
        else if (m + f >= 50 || r >= 50) 
            printf("C"); // Output "C" for satisfactory performance
        // Check if the total score is between 30 and 49 for grade D
        else if (m + f >= 30) 
            printf("D"); // Output "D" for passing but needs improvement
        // If none of the above conditions are met, output "F"
        else 
            printf("F"); // Output "F" for failure

        // Print a newline after each grade output
        printf("\n");
    }

    return 0; // End of the program
}

// <END-OF-CODE>
