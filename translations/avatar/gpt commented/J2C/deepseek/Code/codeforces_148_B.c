#include <stdio.h>

int main() {
    double VP, VD, T, F, C;
    int answer = 0;
    
    // Reading input values for VP, VD, T, F, and C
    scanf("%lf %lf %lf %lf %lf", &VP, &VD, &T, &F, &C);
    
    // If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
    if (VD <= VP) {
        printf("0\n"); // Output 0 as the dog will never catch the person
        return 0; // Exit the program
    }
    
    double start = T; // Start time for the first chase
    
    // Loop to calculate how many times the dog can catch the person
    while (1) {
        // Calculate the distance the person covers before the dog catches up
        double x = start * VP / (VD - VP);
        
        // Check if the distance covered by the person is greater than or equal to C
        if ((start + x) * VP >= C) {
            break; // Exit the loop if the person has covered the required distance
        }
        
        // Update the start time for the next chase
        start += 2 * x + F; // Add the time taken for the dog to return and the time to catch up
        answer++; // Increment the count of catches
    }
    
    // Output the total number of times the dog catches the person
    printf("%d\n", answer);
    
    return 0;
}
