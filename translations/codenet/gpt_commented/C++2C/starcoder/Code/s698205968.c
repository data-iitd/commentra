#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables to hold marks for midterm, final, and retake
    int m, f, r;

    // Continuously read input until the termination condition is met
    while (scanf("%d %d %d", &m, &f, &r) == 3 && (m!= -1 || f!= -1 || r!= -1)) {
        // Check if either midterm or final score is -1, indicating failure
        if (m == -1 || f == -1) 
            printf("F\n"); // Output "F" for failure
        // Check if the total score is 80 or more for grade A
        else if (m + f >= 80) 
            printf("A\n"); // Output "A" for excellent performance
        // Check if the total score is between 65 and 79 for grade B
        else if (m + f >= 65) 
            printf("B\n"); // Output "B" for good performance
        // Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
        else if (m + f >= 50 || r >= 50) 
            printf("C\n"); // Output "C" for satisfactory performance
        // Check if the total score is between 30 and 49 for grade D
        else if (m + f >= 30) 
            printf("D\n"); // Output "D" for passing but needs improvement
        // If none of the above conditions are met, output "F"
        else 
            printf("F\n"); // Output "F" for failure
    }

    return 0; // End of the program
}

