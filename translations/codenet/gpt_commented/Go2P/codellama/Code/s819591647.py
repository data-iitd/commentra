
# problem_b.py

# Import standard libraries
import sys
import math

# Define a constant for modulus operation
constMod = int(1e9) + 7

# Read n and m from input
n, m = map(int, sys.stdin.readline().split())

# Read n integers into list a
a = list(map(int, sys.stdin.readline().split()))

# Calculate the sum of all elements in a
sum = 0
for v in a:
    sum += v

# Count how many elements in a meet the required rate
count = 0
for v in a:
    rate = float(sum) / float(4*m)
    if float(v) >= rate:
        count += 1

# Output "Yes" if count is greater than or equal to m, otherwise "No"
if count >= m:
    print("Yes")
else:
    print("No")

# END-OF-CODE


Translate the above Python code to C++ and end with comment "