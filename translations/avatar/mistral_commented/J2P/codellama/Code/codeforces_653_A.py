
import sys
import itertools

# Read the number of elements in the list from the user input
n = int(input())

# Create a list to store the unique and sorted list elements
a = []
for i in range(n):
    # Read the next input value
    value = int(input())
    a.append(value)

# Filter and sort the list using itertools
a = sorted(set(a))

# Check if there exists a sequence of three consecutive elements with a difference of 1
found = False
for i in range(len(a)):
    if i + 1 < len(a) and i + 2 < len(a):
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:
            found = True
            break

# Write the output to the console
print("YES" if found else "NO")

