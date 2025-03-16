import sys

# Read the number of sets and the maximum element value
n, m = map(int, sys.stdin.readline().split())

# Initialize an array to count occurrences of each element from 1 to 30
x = [0] * 31

# Loop through each set
for _ in range(n):
    # Read the number of elements in the current set
    k = list(map(int, sys.stdin.readline().split()))[0]
    # Loop through each element in the current set
    for _ in range(k):
        # Read an element
        a = int(sys.stdin.readline().split()[0])
        # Increment the count of the element in the array x
        x[a] += 1

# Initialize a variable to store the count of elements that appear in every set
ans = 0

# Loop through each element from 1 to m
for i in range(1, m + 1):
    # Check if the element appears in every set
    if x[i] == n:
        # Increment the count if the condition is met
        ans += 1

# Print the final count of elements that appear in every set
print(ans)
