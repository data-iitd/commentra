
# Declare a variable N to hold the number of elements
N = int(input())

# Create a new scanner to read input from standard input
scanner = input().split()

# Initialize a list v of size N to hold counts of occurrences
v = [0] * N

# Loop through the range from 1 to N-1 to read N-1 integers
for i in range(1, N):
    # Convert the scanned text to an integer
    a = int(scanner[i])
    # Increment the count at the index corresponding to the value read (adjusted for 0-based index)
    v[a-1] += 1

# Loop through the list v to print the counts of occurrences
for e in v:
    # Print each count to the output
    print(e)

# 