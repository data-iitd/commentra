#include<stdio.h> # Include the standard input/output library

int main(): # The entry point of the program
    n = int(input()) # Read an integer value from the standard input and store it in 'n'

    a = [0] * n # Declare an integer array 'a' of size 'n'

    for i in range(n): # Iterate through each element of the array 'a'
        a[i] = int(input()) # Read an integer value from the standard input and store it in the current element of array 'a'

    t = 0 # Initialize the variable 't' to zero

    for i in range(n): # Iterate through each element of the array 'a'
        s = 0 # Initialize the variable 's' to zero for summation

        for j in range(1, n): # Iterate through all other elements of the array 'a' except the current element 'i'
            if j <= i: # If the current index 'j' is less than or equal to the current index 'i', then skip the iteration
                continue

            m = a[i] * a[j] # Multiply the current element 'a[i]' with the next element 'a[j]' and store the result in 'm'

            s = s + m # Add the product 'm' to the sum 's'

        t = t + s # Add the sum 's' to the total sum 't'

    print(t) # Print the total sum 't' to the standard output

    return 0 # Indicate successful termination of the program

