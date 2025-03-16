#include<stdio.h> # Include the standard input/output library

signed main(): # Declare the main function with return type signed
    n,k = int(input()),int(input()) # Read two integers from the standard input and store them in variables n and k
    p = [int(input()) for i in range(n)] # Declare an array p of integers with a size of n and read n integers from the standard input and store them in the array p
    for i in range(n): # Iterate through the array p from index 0 to n-1
        l = i # Initialize variable l to i
        for j in range(i+1,n): # Iterate through the array p from index i+1 to n-1
            if p[j]<p[l]: # If the element at index j is smaller than the element at index l
                l = j # Update the index of the smallest element
        if l!=i: # If the index of the smallest element is not equal to i
            m = p[i] # Swap the elements at indices i and l
            p[i] = p[l]
            p[l] = m
    for i in range(k): # Iterate through the array p from index 0 to k-1
        o += p[i] # Add the element at index i to the variable o
    print(o) # Print the value of the variable o to the standard output
    return 0 # Return 0 to indicate successful execution of the program

