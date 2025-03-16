# Declare variables for the number of elements (N) and the threshold value (X)
N, X = map(int, input().split())

# Initialize a list L of size N to store the elements
L = list(map(int, input().split()))

# Initialize index variable and a variable to accumulate the sum
i = 0
d = 0

# Iterate through the elements of the list L
while i < N:
    # Accumulate the sum of elements
    d += L[i]
    
    # Check if the accumulated sum exceeds the threshold X
    if d > X:
        break # Exit the loop if the sum exceeds X
    
    # Increment the index variable
    i += 1

# Output the number of elements processed before exceeding X
print(i + 1) # i + 1 because we want to count the number of elements

