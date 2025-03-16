# Get the number of nodes 'n' and the number of edges 'k' from user input
u = input
n, k = map(int, u.split())

# Initialize an empty list 'M' of size 'n' to represent the status of each node
M = [int(i) for i in input().split()]

# Initialize a counter 'm' to keep track of the number of nodes printed
m = 0

# Iterate through each node 'j' in the range of 0 to 'n'
for j in range(n):
    # Iterate through each node 'p' in the range of 0 to 'n'
    for p in range(n):
        # Check if the current node 'p' is not yet processed (M[p] == 0)
        if M[p] == 0:
            # Print the index of the current node 'p' and increment the counter 'm'
            print(p + 1, end=' ')
            break
    # Decrement the status of all nodes 'l' in the range of 0 to 'p' (exclusive)
    for l in range(p + 1 - k):
        M[l] -= 1
    # Decrement the status of the current node 'p'
    M[p] -= 1