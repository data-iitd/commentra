
import sys

# Read the size of the array
N = int(input())

# Read the elements of the array
A = list(map(int, input().split()))

# Sort the array
A.sort()

# Find the minimum and maximum values in the array
min_val = A[0]
max_val = A[-1]

# Count the occurrences of the minimum and maximum values
mins = A.count(min_val)
maxs = A.count(max_val)

# Special case: if min == max
if min_val == max_val:
    print(f"{max_val - min_val} {mins * (mins - 1) // 2}")
else:
    # General case: if min!= max
    print(f"{max_val - min_val} {mins * maxs}")

# Debugging method to print debug statements
def debug(*obj):
    print(*obj, file=sys.stderr)

# End of code
