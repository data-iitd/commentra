#include <stdio.h>

int main(void) 
{
    # Initialize variables to store the sum, current number, count of numbers, and min/max values
    sum = 0 # To hold the sum of all numbers
    m, n, i, min, max = 0, 0, 0, 0, 0 # m: current number, n: total count of numbers, i: loop index, min: minimum value, max: maximum value

    # Read the total number of integers to be processed
    scanf("%d\n", &n)

    # Loop through each number to read and process
    for i in range(n):
        # Read the current number
        scanf("%d", &m)
        
        # Add the current number to the sum
        sum += m

        # Initialize min and max with the first number read
        if i == 0:
            min = m # Set min to the first number
            max = m # Set max to the first number
       
        # Update min if the current number is less than the current min
        if min > m:
            min = m # Update min

        # Update max if the current number is greater than the current max
        if max < m:
            max = m # Update max
   
    # Print the minimum, maximum, and sum of the numbers
    printf("%d %d %ld\n", min, max, sum)
}

