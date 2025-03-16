import sys
input = sys.stdin.readline

# Read the number of events (n) and the starting time (s)
n, s = map(int, input().split())

# Initialize the maximum additional time to 0
c = 0

# Loop through each event
for _ in range(n):
    # Read the finish time (f) and the time taken (t) for the current event
    f, t = map(int, input().split())
    
    # Calculate the additional time required if the event starts at time s
    x = t - (s - f)
    
    # Update the maximum additional time if the current event requires more time
    if x > c:
        c = x

# Print the total time including the maximum additional time
print(s + c)
