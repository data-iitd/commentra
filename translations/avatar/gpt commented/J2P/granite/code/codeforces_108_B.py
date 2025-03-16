
import sys # Importing the sys module for handling input and output

# Reading the number of elements in the array
n = int(input())

# Initializing an empty list to store the array elements
a = []

# Loop to read n integers from the user and store them in the list
for i in range(n):
    a.append(int(input()))

# Sorting the list in ascending order
a.sort()

# Loop to check the condition for adjacent elements in the sorted list
for i in range(len(a) - 1):
    # Checking if the next element is less than double the current element
    # and ensuring they are not equal
    if a[i + 1] < a[i] * 2 and a[i]!= a[i + 1]:
        # If the condition is met, print "YES" and exit the program
        print("YES")
        sys.exit()

# If no such pair is found, print "NO"
print("NO")

