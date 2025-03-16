
import sys

# Read the number of test cases, and two integers n and m
tc, n, m = map(int, sys.stdin.readline().split())

# Ensure n is the smaller of the two integers
if n > m:
    n, m = m, n

# Loop through the range from 1 to m
for i in range(1, m + 1):
    # Check if the current value multiplied by tc is within the range [n, m]
    if i * tc >= n and i * tc <= m:
        print("OK")  # Print "OK" if the condition is satisfied
        break  # Exit the loop as we found a valid case
else:
    print("NG")  # Print "NG" if no valid case was found

