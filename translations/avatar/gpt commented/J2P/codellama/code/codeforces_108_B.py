import array // Importing the array module for sorting
import sys // Importing the sys module for reading input

# Reading the number of elements in the array
n = int(sys.stdin.readline())

# Initializing an array of size n
a = array.array('i', [0] * n)

# Loop to read n integers from the user and store them in the array
for i in range(n):
    a[i] = int(sys.stdin.readline())

# Sorting the array in ascending order
a.sort()

# Loop to check the condition for adjacent elements in the sorted array
for i in range(len(a) - 1):
    # Checking if the next element is less than double the current element
    # and ensuring they are not equal
    if a[i + 1] < a[i] * 2 and a[i] != a[i + 1]:
        # If the condition is met, print "YES" and exit the program
        print("YES")
        sys.exit()

# If no such pair is found, print "NO"
print("NO")

