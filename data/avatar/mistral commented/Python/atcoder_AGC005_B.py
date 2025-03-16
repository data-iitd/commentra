# Define the root function which returns the root of a tree node
# This function uses recursion to find the root of a node by traversing up the tree
# until it reaches the root node or a node with the same parent
def root(x):
    return x if par[x] == x else root(par[x])

# Define the same function which checks if two nodes have the same root
# This function is used to check if two nodes belong to the same tree
def same(x, y):
    return root(x) == root(y)

# Define the unite function which merges two trees into one
# This function sets the parent of the smaller tree to the root of the larger tree
# and updates the size of the root node accordingly
def unite(*z):
    x, y = map(root, z)
    if x != y:
        if rank[x] < rank[y]:
            par[x] = y
            size[y] += size[x]
        else:
            par[y] = x
            size[x] += size[y]
            if rank[x] == rank[y]:
                rank[x] += 1

# Read input from standard input and initialize variables
n, *a = map(int, open(0).read().split())
# Initialize parent and rank lists with given size
*par, = range(n)
rank = [1] * n
size = [1] * n
# Initialize a list b to store the indices of elements in the input list a
b = [0] * n
# Iterate through the input list and store the indices of elements in list b
for i, t in enumerate(a):
    b[t - 1] = i

# Initialize a variable c to store the result
c = 0

# Iterate through the list b from the second element to the first
for k in b[::-1]:
    # Initialize variables l and r to store the sizes of the left and right subtrees
    l, r = 1, 1
    
    # Check if the current node k has a larger element to its left
    if k > 0 and a[k - 1] > a[k]:
        # If yes, update l with the size of the left subtree
        l += size[root(k - 1)]
        # Merge the left and current subtrees
        unite(k - 1, k)

    # Check if the current node k has a larger element to its right
    if k + 1 < n and a[k + 1] > a[k]:
        # If yes, update r with the size of the right subtree
        r += size[root(k + 1)]
        # Merge the right and current subtrees
        unite(k + 1, k)

    # Update the result variable c with the product of the sizes of the left and right subtrees
    # and the value of the current element
    c += l * r * a[k]

# Print the result
print(c)
