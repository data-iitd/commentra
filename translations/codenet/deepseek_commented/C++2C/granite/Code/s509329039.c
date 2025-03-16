
#include <stdio.h> // Include standard input/output library for basic input/output operations
#include <stdlib.h> // Include standard library for general utilities such as dynamic memory allocation, conversions, and others
#include <string.h> // Include string library for string manipulation
#include <math.h> // Include math library for mathematical functions
#include <assert.h> // Include assert library for debugging with assertions
#include <time.h> // Include ctime library for date and time functions
#include <complex.h> // Include complex library for complex number operations

int main(){
    int n,m;
    scanf("%d %d",&n,&m); // Read the number of digits and the number of constraints
    int s[m],c[m]; // Declare arrays to store the positions and values of constraints
    for(int i=0;i<m;i++){
        scanf("%d %d",&s[i],&c[i]); // Read the position and value of each constraint
        s[i]--; // Decrement the position by 1 to convert to 0-based index
    }
    for(int i=0;i<1000;i++){
        char st[10]; // Declare a character array to store the current number as a string
        sprintf(st,"%d",i); // Convert the current number to a string
        if (strlen(st)!=n){ // Check if the length of the string is equal to the number of digits
            continue; // If not, continue to the next iteration
        }
        //printf("%s\n",st); // Print the current number (for debugging purposes)
        int f=1; // Initialize a flag to 1 (true)
        for(int j=0;j<m;j++){
            if(st[s[j]]==c[j]+'0'){ // Check if the digit at the constraint position matches the constraint value
                // Do nothing (continue to the next iteration)
            }else{
                f=0; // If any constraint is not met, set the flag to 0 (false)
            }
        }
        if(f){ // Check if all constraints are met
            printf("%d\n",i); // Print the valid number
            return 0; // Exit the program
        }
    }
    printf("-1\n"); // If no valid number is found, print -1
    return 0; // End the program
}
