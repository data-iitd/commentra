#include<stdio.h>

int main(void) {
    # Declare variables
    i = 0 # i for loop iteration
    n = 0 # n for number of inputs
    tmp = 0 # tmp for temporary input storage
    min = 1000000 # Initialize min
    max = -1000000 # Initialize max
    sum = 0 # Initialize sum

    # Read the number of integers to be processed
    scanf("%d", &n)
    
    # Loop to read n integers
    for i in range(n):
        # Read the next integer
        scanf("%d", &tmp)
        
        # Update min if the current number is smaller
        if min > tmp:
            min = tmp
        
        # Update max if the current number is larger
        if max < tmp:
            max = tmp
        
        # Add the current number to the sum
        sum += tmp

    # Print the minimum, maximum, and sum of the numbers
    printf("%ld %ld %ld\n", min, max, sum)

    return 0 # Indicate that the program ended successfully
}
