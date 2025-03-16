# Import necessary libraries
import sys

# Read the number of constraints (n) and the number of conditions (m)
n, m = map(int, input().split())

# Initialize lists to store the positions (s) and corresponding values (c)
s = []
c = []

# Read the constraints into the lists
for _ in range(m):
    pos, val = map(int, input().split())
    s.append(pos - 1)  # Adjust for 0-based indexing
    c.append(val)

# Iterate through all possible numbers from 0 to 999
for i in range(1000):
    st = str(i)  # Convert the number to a string

    # Skip numbers that do not have the required length
    if len(st) != n:
        continue

    # Flag to check if the current number satisfies all conditions
    f = True

    # Check each condition against the current number
    for j in range(m):
        if st[s[j]] != str(c[j]):
            # Condition is not satisfied, set flag to False
            f = False
            break

    # If all conditions are satisfied, print the number and exit
    if f:
        print(i)
        sys.exit(0)

# If no valid number is found, output -1
print(-1)

# <END-OF-CODE>
