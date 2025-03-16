#######
# Code
#######

# Read the first line of input containing the number of nodes 'n' and edges 'm'
(n, m) = [int(x) for x in input().split()]

# Initialize a list 'p' of numbers from 1 to 'n'
p = [x for x in range(1, n+1)]

# Read the second line of input containing the heights of the nodes
h = [int(x) for x in input().split()]

# Create a dictionary 'hp' using list comprehension to store node number as key and height as value
hp = dict(zip(p, h))

# Initialize an empty dictionary 'path' to store the graph
path = {i: [] for i in range(1, n+1)}

# Read 'm' lines of input containing edges and add them to the 'path' dictionary
for _ in range(m):
    a, b = [int(x) for x in input().split()]
    path[a].append(b)
    path[b].append(a)

# Initialize a counter 'c' to store the number of valid paths
c = 0

# Iterate through each node in the graph and check if it forms a valid path
for i, v in path.items():
    # Initialize a flag 'f' to check if the current node is a valid starting point
    f = 0
    # Iterate through each neighbor of the current node and check if it is a valid ending point
    for j in v:
        # If the height of the current node is less than or equal to the height of its neighbor,
        # then it is not a valid path and we set the flag 'f' to 1 and break the loop
        if hp[i] <= hp[j]:
            f = 1
            break
    # If the flag 'f' is still 0 after checking all neighbors, then this node forms a valid path
    # and we increment the counter 'c'
    if f == 0:
        c += 1

# Print the final result, i.e., the number of valid paths
print(c)
