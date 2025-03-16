#include <stdio.h> 
#include <stdbool.h> 

// Function to determine if a given year is a leap year
bool check_leap(int y) { 
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); 
} 

int main() { 
    // Read the year input from the user
    int y; 
    scanf("%d", &y); 
    
    // Check if the input year is a leap year
    bool leap = check_leap(y); 
    
    // Initialize variables to keep track of the total days and the modulus
    int sum = 0; 
    int mod = 0; 
    
    // Start an infinite loop to find the next matching year
    for (int i = y + 1; ; i++) { 
        // Check if the current year is a leap year and add the corresponding days to sum
        if (check_leap(i)) { 
            sum += 366; 
        } else { 
            sum += 365; 
        } 
        
        // Check if the total number of days is a multiple of 7
        if (sum % 7 == 0) { 
            // If the leap year status matches with the input year, print the year and exit
            if ((check_leap(i) && leap) || (!check_leap(i) && !leap)) { 
                printf("%d\n", i); 
                return 0; 
            } else { 
                // Continue to the next iteration if the leap year status does not match
                continue; 
            } 
        } 
    } 
} 

