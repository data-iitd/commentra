
import sys

# Read the number of elements from input
N = int(input())

# Read N integers from input and store them in the list A
A = list(map(int, input().split()))

# Sort the list A to easily find the minimum and maximum values
A.sort()

# Identify the minimum and maximum values in the sorted list
min_val = A[0]
max_val = A[-1]

# Initialize counters for occurrences of min and max values
mins = 0
maxs = 0

# Count how many times the minimum and maximum values occur in the list
for value in A:
    if value == min_val:
        mins += 1
    if value == max_val:
        maxs += 1

# If all elements are the same (min equals max)
if min_val == max_val:
    # Calculate the difference (which is 0) and the number of ways to choose 2 from mins
    print(max_val - min_val, mins * (mins - 1) // 2)
else:
    # Calculate the difference and the product of occurrences of min and max
    print(max_val - min_val, mins * maxs)

# Debugging method to print objects in a readable format
def debug(*obj):
    print(*obj, file=sys.stderr)

# End of code
