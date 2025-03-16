# Package declaration for the main Python program
import sys

# Import the'math' package for mathematical operations
import math

# Import the'sort' package for sorting operations
import sort

# Initialize an integer variable 'n' and read its value from the standard input
n = int(input())

# Create an array 'a' of 'n' float64 elements
a = [0.0 for i in range(n)]

# Read 'n' float64 values from the standard input and assign them to the array 'a'
for i in range(n):
	a[i] = float(input())

# Iterate through the array 'a' 'n-1' times and sort it using the'sort.sort' function
for i in range(n-1):
	sort.sort(a)

# Initialize an empty list 'na' of float64
na = []

# Iterate through the list 'a' starting from index 2 and append its elements to the list 'na'
for j in range(2, len(a)):
	na.append(a[j])

# Reassign the value of the list 'a' with the list 'na' and the first two elements being the average of the first two elements of the original list 'a'
na.append((a[0]+a[1])/2)
a = na

# Print the first element of the sorted list 'a' to the standard output
print(a[0])

# 