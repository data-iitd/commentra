
import sys

# Read the number of elements in the array
n = int(input())

# Initialize an array of size n to store the input values
a = list(map(int, input().split()))

# Sort the array in ascending order
a.sort()

# Store the minimum value from the sorted array
min_value = a[0]

# Check if all elements in the array are divisible by the minimum value
for value in a:
    if value % min_value!= 0:
        # If any element is not divisible, print -1 and exit
        print(-1)
        sys.exit()

# If all elements are divisible, print the minimum value
print(min_value)

