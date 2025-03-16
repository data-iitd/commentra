########
# Code #
########

# Take the number of houses N as input
N = int(input())

# Read a list of heights Hs of houses from the standard input
Hs = list(map(int, input().split()))

# Initialize answer ans to 0
ans = 0

# Initialize maximum height maxH to 0
maxH = 0

# Iterate through each house height H in the list Hs
for H in Hs:

    # If the current maximum height maxH is less than or equal to the height H of the current house,
    # then increment the answer ans by 1 and update the maximum height maxH to the height H
    if maxH <= H:
        ans += 1
        maxH = H

# Print the final answer
print(ans)
