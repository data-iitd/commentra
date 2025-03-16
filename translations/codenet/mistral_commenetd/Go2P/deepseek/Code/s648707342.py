import sys

# Read the number of arms, n
n = int(input().strip())

# Initialize a list of arm structures, as
as = []

# Read and initialize each arm structure in the list
for _ in range(n):
    # Read the position and length of the arm
    x, l = map(int, input().strip().split())

    # Initialize the left and right fields of the arm structure
    as.append((x - l, x + l))

# Sort the list based on the right field of the arm structures
as.sort(key=lambda arm: arm[1])

# Initialize answer variable, ans, and right variable, r
ans = 1
r = as[0][1]

# Iterate through the list and update the answer and right variable accordingly
for i in range(1, n):
    if as[i][0] >= r:  # Check if the left end of the current arm is greater than or equal to the right end of the previous arm
        ans += 1  # Increment the answer if it is
        r = as[i][1]  # Update the right variable with the right end of the current arm

# Print the answer
print(ans)

# End-of-code
