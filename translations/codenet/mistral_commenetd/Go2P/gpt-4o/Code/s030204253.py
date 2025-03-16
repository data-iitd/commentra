# Import the necessary module for input and output operations
import sys

# Initialize an integer variable 'n' and read its value from the standard input
n = int(sys.stdin.readline().strip())

# Create a list 'a' of 'n' float elements
a = [0.0] * n

# Read 'n' float values from the standard input and assign them to the list 'a'
for i in range(n):
    a[i] = float(sys.stdin.readline().strip())

# Sort the list 'a'
a.sort()

# Initialize an empty list 'na' of float
na = []

# Iterate through the list 'a' starting from index 2 and append its elements to the list 'na'
for j in range(2, len(a)):
    na.append(a[j])

# Reassign the value of the list 'a' with the list 'na' and the first two elements being the average of the first two elements of the original list 'a'
na.append((a[0] + a[1]) / 2)
a = na

# Print the first element of the sorted list 'a' to the standard output
print(a[0])

# <END-OF-CODE>
