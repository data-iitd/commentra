# Importing the sys module and assigning its stdin input to a variable named 'input'
import sys

# Assigning the stdin input to a variable named 'input'
input = sys.stdin.readline

# Reading the first line of input which contains the number of elements 'n' in the list 'w'
n = int(input())

# Initializing an empty list 'd' to store the indices of the elements that satisfy the condition
d = []

# Iterating through each element 'i' in the list 'w'
for i in range(n):
    # Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
    # and checking if it's equal to the current element 'w[i]'
    if (x - w[i]) / (n - 1) == w[i]:
        # If the condition is true, append the index 'i+1' to the list 'd'
        d.append(i + 1)

# Printing the length of the list 'd'
print(len(d))

# Printing the elements of the list 'd' separated by a space
print(' '.join(map(str, d)))
