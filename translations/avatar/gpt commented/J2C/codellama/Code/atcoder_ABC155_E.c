#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

int main() { 
    // Define a constant for a large number (infinity) for potential use in calculations
    const long INF = (long) 1e15; 
    
    // Create a Scanner object to read input from the console
    // Scanner sc = new Scanner(System.in); 
    char number[100]; 
    printf("Enter a number: "); 
    scanf("%s", number); 
    
    // Read the input number as a string
    // String number = sc.next(); 
    
    // Initialize an array to hold the digits of the number in reverse order
    int digits[strlen(number) + 1]; 
    
    // Convert the input string into an array of digits (in reverse order)
    for (int i = 0; i < strlen(number); i++) { 
        digits[i] = number[strlen(number) - 1 - i] - '0'; 
    } 
    
    // Initialize a variable to count the total number of bills
    int bills = 0; 
    
    // Process each digit to calculate the total number of bills needed
    for (int i = 0; i <= strlen(number); i++) { 
        // Handle carry over for digits equal to 10
        if (digits[i] == 10) { 
            digits[i + 1]++; 
            digits[i] = 0; 
        } 
        
        // If the digit is less than 5, add it directly to the bills
        if (digits[i] < 5) { 
            bills += digits[i]; 
        } 
        // If the digit is exactly 5, check the next digit for rounding
        else if (digits[i] == 5) { 
            if (digits[i + 1] >= 5) { 
                digits[i + 1]++; 
            } 
            bills += 5; 
        } 
        // If the digit is greater than 5, round up to the next ten
        else { 
            digits[i + 1]++; 
            bills += 10 - digits[i]; 
        } 
    } 
    
    // Output the total number of bills calculated
    printf("Total number of bills: %d\n", bills); 
    
    return 0; 
} 

