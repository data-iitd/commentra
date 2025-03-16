#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    # Declare variables
    n = 0 # n: number of elements
    i = 0 # i: loop index
    h = [] # Array to store heights
    max = -1 # Variable to track the maximum height
    flag = 0 # Flag to indicate if the condition is met

    # Read the number of elements
    n = int(input())

    # Loop to read heights and determine the maximum height
    for i in range(n):
        # Read height into the array
        h.append(int(input()))
        
        # Update maximum height if current height is greater
        if max < h[i]: max = h[i]

        # Check if the difference between max height and current height is 2 or more
        if max - h[i] >= 2: flag = 1 # Set flag if condition is met
    # Output result based on the flag value
    if flag == 1:
        print("No") # If flag is set, print "No"
    else:
        print("Yes") # If flag is not set, print "Yes"

    return 0 # Exit the program
}
