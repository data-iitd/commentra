# Package declaration for the main Python program
import sys

# Initialize an integer variable 'n' and read its value from the standard input
n = int(sys.stdin.readline())

# Create an array 'a' of 'n' float64 elements
a = [0.0] * n

# Read 'n' float64 values from the standard input and assign them to the array 'a'
for i in range(n):
    a[i] = float(sys.stdin.readline())

# Iterate through the array 'a' 'n-1' times and sort it using the 'Sort.Sort' function
for i in range(n-1):
    a.sort()

# Initialize an empty slice 'na' of float64
na = []

# Iterate through the slice 'a' starting from index 2 and append its elements to the slice 'na'
for j in range(2, len(a)):
    na.append(a[j])

# Reassign the value of the slice 'a' with the slice 'na' and the first two elements being the average of the first two elements of the original slice 'a'
na.append((a[0] + a[1]) / 2)
a = na

# Print the first element of the sorted slice 'a' to the standard output
print(a[0])

