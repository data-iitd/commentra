
# Read the number of elements in the memory array from the standard input
N = int(input())

# Allocate memory for an integer array of size N+1 to store the memory locations of each process
mem = [0] * (N + 1)

for i in range(1, N + 1): # Read the memory locations of each process and store them in the mem array
    mem[int(input())] = i

maxcnt = 1 # Initialize maxcnt to 1, which will store the maximum length of a consecutive increasing sequence of memory locations
cnt = 1 # Initialize cnt to 1, which will store the current length of such a sequence

for i in range(1, N): # Traverse the mem array and update maxcnt and cnt variables accordingly
    if mem[i] < mem[i + 1]:
        cnt += 1
    else:
        maxcnt = max(maxcnt, cnt)
        cnt = 1

# Update maxcnt with the length of the last consecutive increasing sequence
maxcnt = max(maxcnt, cnt)

print(N - maxcnt) # Print the result N - maxcnt to the standard output

