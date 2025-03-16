
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int s, x, d=2; 
    scanf("%d", &s); // Read the initial number from the user
    bool a[s+1];
    a[s] = true; // Mark the initial number as encountered

    while(1) { // Start an infinite loop
        if(s%2==0){ // Check if the current number is even
            x = s/2; // Halve the number
            if(a[x]) { // Check if the halved number has been encountered before
                printf("%d\n", d); // Output the current step count and terminate the program
                return 0;
            }
            a[x] = true; // Mark the halved number as encountered
        } else { // The current number is odd
            x = 3*s + 1; // Triple the number and add one
            if(a[x]) { // Check if the new number has been encountered before
                printf("%d\n", d); // Output the current step count and terminate the program
                return 0;
            }
            a[x] = true; // Mark the new number as encountered
        }
        s = x; // Update the current number to the new number
        d++; // Increment the step count
    }

    printf("%d\n", d); // Output the step count (this line will never be reached)

    return 0;
}
