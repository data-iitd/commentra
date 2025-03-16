
import sys

# Read the number of groups of three integers
n = int(input())

# Initialize a list to hold 3*n integers
ar = []

# Populate the list with integers from input
for _ in range(3*n):
    ar.append(int(input()))

# Sort the list of integers in ascending order
ar.sort()

# Initialize a variable to hold the sum of selected integers
sum = 0

# Calculate the sum of the second largest integer from each group of three
for i in range(n):
    sum += ar[3*n-(i+1)*2] # Select the second largest integer from the sorted list

# Print the final computed sum
print(sum)

# 