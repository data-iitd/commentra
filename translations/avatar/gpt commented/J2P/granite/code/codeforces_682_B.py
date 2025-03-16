
import sys

# Read the number of elements
n = int(input())

# Initialize an empty list to store the input integers
list = []

# Read n integers from input and add them to the list
for i in range(n):
    list.append(int(input()))

# Sort the list of integers in ascending order
list.sort()

# Initialize a counter to track the maximum consecutive integer
c = 1

# Iterate through the sorted list to find the maximum consecutive integer
for i in range(n):
    # If the current integer is greater than or equal to the counter, increment the counter
    if list[i] >= c:
        c += 1

# Print the result which is the maximum consecutive integer found
print(c)

# Debugging method to print objects to the error output
def debug(*obj):
    print(*obj, file=sys.stderr)

# End of code
