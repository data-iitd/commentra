
import array // Importing array module
import sys // Importing sys module

n = int(sys.stdin.readline().strip()) // Read the number of elements (n) from the user
a = array.array('i', [0] * n) // Initialize an array 'a' of size n to store the elements
r = 0 // Initialize a variable 'r' to store the result of XOR operation

# Read the elements of the array 'a' from the user and perform XOR operation on each element
for i in range(n):
    a[i] = int(sys.stdin.readline().strip())
    r ^= a[i]

# Print the result of XOR operation for each element in the array 'a'
for i in range(n):
    if i != 0: print(" ", end="") // Print a space before each element except the first one
    print(r ^ a[i], end="") // Print the result of XOR operation for each element

print() # Print a newline at the end of the output

