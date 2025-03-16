# Importing the 'defaultdict' from the 'collections' module
from collections import defaultdict

# Taking the number of nodes 'N' and the number of edges 'K' as input
N, K = map(int, input().split())

# Initializing the list 'L' with the given number of edges
L = list(map(int, input().split()))

# Adding a special node with index -1 at the beginning of the list 'L'
L.insert(0, -1)

# Initializing an empty list 'path' to store the shortest path
path = [1]

# Initializing variables 'ind' and 'count'
ind = 0
count = 0

# Initializing variables 'x' and 't'
x = 1
t = -1

# Initializing a boolean variable 'flag'
flag = False

# Creating an empty dictionary 'Hash' using defaultdict
Hash = defaultdict(lambda: 0)

# Traversing through all the nodes from 0 to 'N'
for i in range(N+1):
    # Getting the next edge 'ne' from the current node 'x'
    ne = L[x]

    # Checking if the current node 'ne' is already in the hash table 'Hash'
    if Hash[ne] != 0:
        # Setting the boolean variable 'flag' to True and storing the index of the previous occurrence of the node 'ne' in 't'
        flag = True
        t = Hash[ne]
        break

    # Appending the next edge 'ne' to the list 'path'
    path.append(ne)

    # Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
    ind += 1
    Hash[ne] = ind

    # Updating the current node 'x' to the next node 'ne'
    x = ne

# Checking if there is a cycle in the graph
if flag == True:
    # Storing the list of nodes in the cycle 'loop'
    loop = path[t:]

    # Checking if the length of the path is less than 'K'
    if len(path) < K:
        # Printing the 'K'th node in the path
        print(path[K])

    # If the length of the path is greater than or equal to 'K', then we need to find the 'K'th node in the cycle 'loop'
    else:
        # Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
        K = K - len(path)
        K = K % len(loop)

        # Printing the 'K'th node in the cycle 'loop'
        print(loop[K])

# If there is no cycle in the graph, then we simply print the 'K'th node in the path
else:
    # Printing the 'K'th node in the path
    print(path[K-1])
