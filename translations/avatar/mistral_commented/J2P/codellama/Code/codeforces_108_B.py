
import array
import sys

# Reading the number of elements in the array from user input
n = int(input())

# Creating an integer array of size n
a = array.array('i', [0] * n)

# Initializing the array with user input
for i in range(n):
    a[i] = int(input())

# Sorting the array in ascending order
a.sort()

# Checking if there is any pair of adjacent elements that satisfy the condition
for i in range(n - 1):
    # Checking if the next element is less than twice the current element and they are not the same
    if a[i + 1] < a[i] * 2 and a[i] != a[i + 1]:
        print("YES")
        sys.exit()

# If no pair is found, printing "NO"
print("NO")

