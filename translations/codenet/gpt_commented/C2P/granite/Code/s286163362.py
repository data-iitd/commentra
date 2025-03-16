
import sys

# Global arrays to hold data and sequence counts
data = [0] * 111111
seq = [0] * 222222

# Function to return the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Infinite loop to continuously read input until termination condition
while True:
    # Read values for n and k
    n, k = map(int, input().split())
    
    # Break the loop if both n and k are zero
    if n == 0 and k == 0:
        break

    # Initialize data and seq arrays to zero
    data = [0] * (n + 1)
    seq = [0] * (n + 2)

    # Read k integers and count their occurrences in the data array
    for _ in range(k):
        t = int(input())
        data[t] += 1

    # Initialize pointer for the sequence array
    p = 0

    # Build the seq array based on the data array
    for i in range(1, n + 1):
        # If the current index has data, increment the sequence count
        if data[i]:
            seq[p] += 1
        else:
            # If no data, move the pointer by 2
            p += 2

    # Increment pointer to account for the last sequence
    p += 1

    # Calculate the maximum sequence length based on the presence of data[0]
    if data[0]:
        # If data[0] exists, consider sequences with gaps
        for i in range(p):
            ret = max(ret, seq[i] + seq[i + 2] + 1)
    else:
        # If data[0] does not exist, consider sequences without gaps
        for i in range(p):
            ret = max(ret, seq[i])

    # Print the maximum sequence length found
    print(ret)

