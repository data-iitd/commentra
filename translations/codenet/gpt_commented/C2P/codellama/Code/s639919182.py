#include <stdio.h>

int main(void)
{
    # Declare an array to hold 10 integers
    v = [0] * 10
    
    # Initialize a variable to hold the sum of the integers
    sum = 0
    
    # Declare a loop variable
    i = 0
    
    # Prompt the user to enter 10 integers and store them in the array
    for i in range(10):
        v[i] = int(input())
    
    # Calculate the sum of the integers stored in the array
    for i in range(10):
        sum += v[i]
    
    # Output the calculated sum to the console
    print(sum)
    
    # Return 0 to indicate successful completion of the program
    return 0
}

