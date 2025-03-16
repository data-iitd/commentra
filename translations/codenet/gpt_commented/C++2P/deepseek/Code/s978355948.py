# Read the values of N and X from standard input
N, X = map(int, input().split())

# Read N elements into a list L
L = list(map(int, input().split()))

# Initialize index variable and a variable to accumulate the sum
i = 0
d = 0

# Iterate through the elements of the list L
for l in L:
    # Accumulate the sum of elements
    d += l
    
    # Check if the accumulated sum exceeds the threshold X
    if d > X:
        break  # Exit the loop if the sum exceeds X
    
    # Increment the index
    i += 1

# Output the number of elements processed before exceeding X
print(i + 1)  # i + 1 because we want to count the number of elements
