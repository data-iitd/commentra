import sys

# Optimize input/output operations
input = sys.stdin.readline

# Read the number of elements
n = int(input())

# Read the elements into a list
p = list(map(int, input().split()))

# Initialize a counter for the number of valid triplets
ans = 0

# Loop through the array to check for increasing or decreasing triplets
for i in range(n - 2):
    # Check if the current triplet is strictly decreasing
    if p[i] > p[i+1] and p[i+1] > p[i+2]:
        ans += 1

    # Check if the current triplet is strictly increasing
    if p[i] < p[i+1] and p[i+1] < p[i+2]:
        ans += 1

# Output the total count of valid triplets
print(ans)
