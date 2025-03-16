
import sys
input = sys.stdin.readline

# Read the number of elements in the list `w`
n = int(input())

# Read the list of integers `w`
w = list(map(int, input().split()))

# Initialize the variable `c` to 2
c = 2

# Loop through each element `i` in the list `w`
for i in w:
    # Check if `i` is equal to 1
    if i == 1:
        # Print the current value of `c`
        print(c)
    # Check if `i` is even
    elif i % 2 == 0:
        # Toggle the value of `c` between 2 and 3-c (i.e., 1 or 3)
        c = 3 - c
        # Print the new value of `c`
        print(c)
    # If `i` is odd
    else:
        # Print the current value of `c`
        print(c)

