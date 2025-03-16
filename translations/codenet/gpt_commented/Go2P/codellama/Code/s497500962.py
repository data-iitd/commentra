
# Read the values for R, G, B, and N from standard input
R = int(input()) # Number of red items
G = int(input()) # Number of green items
B = int(input()) # Number of blue items
N = int(input()) # Total number of items to choose

ans = 0 # Variable to store the count of valid combinations

# Iterate over possible counts of red items (x)
for x in range(N+1):
    # Iterate over possible counts of green items (y)
    for y in range(N+1):
        # Calculate the remaining items after choosing x red and y green
        tmp = N - R*x - G*y
        # Check if the remaining items can be fully represented by blue items
        if tmp >= 0 and tmp % B == 0:
            ans += 1 # Increment the count of valid combinations

# Output the total count of valid combinations
print(ans)

