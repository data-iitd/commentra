#######
# Code
#######

# Define the number of nodes 'n' and the number of edges 'm'
n, m = map(int, input().strip().split())

# Initialize an output list 'out' of size 'n' with zeros
out = [0 for _ in range(n)]

# Initialize a complement list 'comp' of size 'n' with values 'i+2' for 'i' in range(n)
comp = [i+2 for i in range(n)]

# Process each edge in the given 'm' edges
for _ in range(m):
    # Read the left node 'l', right node 'r', and value 'x' of the current edge
    l, r, x = map(int, input().strip().split())
    
    # Set the initial index 't' to the left node 'l'
    t = l
    
    # Iterate through the nodes from 'l' to 'r'
    while t <= r:
        # Get the next value in the complement list 'comp'
        next_val = comp[t-1]
        
        # If the current node 't' in the output list 'out' is zero and it's not the value 'x'
        if out[t-1] == 0 and t != x:
            # Update the output list 'out' with the value 'x' at index 't-1'
            out[t-1] = x
        
        # Update the complement list 'comp' with the next value or the value 'x' depending on the condition
        comp[t-1] = r+1 if t >= x else x
        
        # Update the index 't' to the next value in the complement list 'comp'
        t = next_val
# Print the output list 'out'
print(*out)
