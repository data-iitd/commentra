
import sys

# Reading the number of elements (n) from the user
n = int(input())

# Initializing a variable to store the result of matching elements
result = 0

# Creating two lists to hold the input values
h = [] # List to store the first set of integers
g = [] # List to store the second set of integers

# Reading n integers into the first list (h)
for i in range(n):
    h.append(int(input())) # Storing input in list h

# Reading n integers into the second list (g)
for i in range(n):
    g.append(int(input())) # Storing input in list g

# Comparing each element of list h with each element of list g
for i in range(n):
    for j in range(n):
        # If a match is found, increment the result counter
        if h[i] == g[j]:
            result += 1 # Incrementing the count of matches

# Outputting the total number of matches found
print(result)

