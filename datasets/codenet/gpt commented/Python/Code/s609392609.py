# Read an integer input for the number of elements in the list
n = int(input())

# Read a list of integers from input
t = list(map(int, input().split()))

# Read an integer input for the number of queries
m = int(input())

# Loop through each query
for i in range(m):
    # Read the position (p) and the new value (x) for the current query
    p, x = map(int, input().split())
    
    # Initialize a variable to hold the sum of the modified list
    s = 0
    
    # Loop through each index in the original list
    for j in range(len(t)):
        # If the current index is the position to be modified
        if j == p - 1:
            # Add the new value x to the sum
            s += x
        else:
            # Otherwise, add the original value from the list
            s += t[j]
    
    # Print the computed sum for the current query
    print(s)
