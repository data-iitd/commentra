# Read input values for n and k
u = input
n, k = map(int, u().split())

# Read the list of integers M from input
M = [int(i) for i in u().split()]

# Initialize a variable m to zero (not used in the current logic)
m = 0

# Outer loop to iterate over each index j in the range of n
for j in range(n):
    # Inner loop to find the first index p where M[p] is zero
    for p in range(n):
        if (0 == M[p]):
            # Print the index (1-based) where M[p] is zero
            print(p + 1, end=' ')
            break
    
    # Decrease the values in M from the start up to p + 1 - k
    for l in range(p + 1 - k):
        M[l] -= 1
    
    # Decrease the value at index p in M
    M[p] -= 1
