#include<stdio.h>  # Include the standard input/output library
int main():       # Define the main function

    # Declare integer variables to store input values and intermediate results
    a, b, c, d, i, j = 0, 0, 0, 0, 0, 0

    # Read four integers from the user
    a, b, c, d = input("Enter four integers: ").split()

    # Perform multiplication operations and store the results in i and j
    i = int(a) * int(b)
    j = int(c) * int(d)

    # Use an if-else statement to compare the results and print the larger one
    if i > j:
        print(i)
    else:
        print(j)

    # Return 0 to indicate successful execution
    return 0

