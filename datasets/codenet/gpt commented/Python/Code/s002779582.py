# Read the number of heights from user input
N = int(input())

# Read the heights into a list, converting each input to an integer
Hs = list(map(int, input().split()))

# Initialize the answer counter and the maximum height encountered
ans = 0
maxH = 0

# Iterate through each height in the list
for H in Hs:
    # Check if the current height is greater than or equal to the maximum height seen so far
    if maxH <= H:
        # Increment the count of visible heights
        ans += 1
        # Update the maximum height to the current height
        maxH = H

# Print the total count of visible heights
print(ans)
