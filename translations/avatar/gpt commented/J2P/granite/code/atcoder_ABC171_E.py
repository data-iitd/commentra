
import sys

# Read the number of elements in the array
n = int(input())

# Initialize an array to hold the input integers
a = list(map(int, input().split()))

# Variable to hold the cumulative XOR of all elements
r = 0

# Read each integer from input and compute the cumulative XOR
for i in range(n):
    r ^= a[i] # Update the cumulative XOR with the current element

# For each element in the array, print the result of XORing the cumulative XOR with the element
for i in range(n):
    if i!= 0:
        sys.stdout.write(" ") # Print a space before the next number if it's not the first element
    sys.stdout.write(str(r ^ a[i])) # Print the result of XORing the cumulative XOR with the current element

print() # Print a newline after the output

