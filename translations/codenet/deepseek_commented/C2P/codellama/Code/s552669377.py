#include<stdio.h> # Include the standard input-output header file

int main(void):
    int i, n, tmp; # Declare loop counter, number of elements, and temporary storage variable
    long long int min = 1000000, max = -1000000, sum = 0; # Declare and initialize min, max, and sum

    scanf("%d", &n); # Read the number of elements

    for i in range(n): # Loop through the number of elements
        scanf("%d", &tmp); # Read an integer value into tmp
        if min > tmp: min = tmp; # Update min if tmp is smaller
        if max < tmp: max = tmp; # Update max if tmp is larger
        sum += tmp; # Add tmp to sum

    printf("%ld %ld %ld\n", min, max, sum); # Print the results

    return 0; # Return 0 to indicate successful execution

