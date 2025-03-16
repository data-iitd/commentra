
# Importing the sys module to use the input function
import sys

# Reading the number of elements in the array
n = int(input())

# Initializing an array of size n
a = [0] * n

# Loop to read n integers from the user and store them in the array
for i in range(n):
    a[i] = int(input())

# Sorting the array in ascending order
a.sort()

# Loop to check the condition for adjacent elements in the sorted array
for i in range(n - 1):
    # Checking if the next element is less than double the current element
    # and ensuring they are not equal
    if a[i + 1] < a[i] * 2 and a[i]!= a[i + 1]:
        # If the condition is met, print "YES" and exit the program
        print("YES")
        sys.exit()

# If no such pair is found, print "NO"
print("NO")

