import sys

# Use readline for faster input reading
input = sys.stdin.readline

# Read the number of intervals (n) and the starting point (s)
n, s = map(int, input().split())

# Initialize a variable to keep track of the maximum additional distance (c)
c = 0

# Iterate over each interval
for _ in range(n):
    # Read the start (f) and end (t) of the interval
    f, t = map(int, input().split())
    
    # Calculate the additional distance that can be covered
    x = t - (s - f)
    
    # Update the maximum additional distance if the current one is greater
    if x > c:
        c = x

# Output the total distance covered, which is the starting point plus the maximum additional distance
print(s + c)
