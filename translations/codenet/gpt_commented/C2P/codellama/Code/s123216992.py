#include <stdio.h>

# Function to swap the values of two integers
def swap(a, b):
    tmp = a # Temporary variable to hold one of the values during swap
    a = b # Assign the value pointed by b to the location pointed by a
    b = tmp # Assign the value stored in tmp to the location pointed by b

while True: # Infinite loop to continuously read input until termination condition is met
    # Read two integers from user input
    a, b = input().split()
    
    # Check for the termination condition (both inputs are zero)
    if a == '0' and b == '0': break

    # If the second number is less than the first, swap them
    if int(b) < int(a): swap(a, b)
    
    # Print the sorted values of a and b
    print(a, b)

# END-OF-CODE
