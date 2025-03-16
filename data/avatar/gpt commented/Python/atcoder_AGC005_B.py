# Define a function to find the root of an element using path compression
root = lambda x: x if par[x] == x else root(par[x])

# Define a function to check if two elements belong to the same set
same = lambda x, y: root(x) == root(y)

# Define a function to unite two sets containing elements z
def unite(*z):
    # Find the roots of the elements z
    x, y = map(root, z)
    
    # If the roots are different, unite the sets
    if x != y:
        # Union by rank: attach the smaller tree under the larger tree
        if rank[x] < rank[y]:
            par[x] = y  # Make y the parent of x
            size[y] += size[x]  # Update the size of the new root
        else:
            par[y] = x  # Make x the parent of y
            size[x] += size[y]  # Update the size of the new root
            
            # If ranks are equal, increment the rank of the new root
            if rank[x] == rank[y]:
                rank[x] += 1

# Read input values: first value is n, followed by n integers
n, *a = map(int, open(0).read().split())

# Initialize the parent array where each element is its own parent
*par, = range(n)

# Initialize rank and size arrays for union-find structure
rank = [1] * n  # All elements start with rank 1
size = [1] * n  # All elements start with size 1

# Create an array to store the indices of elements in a
b = [0] * n
for i, t in enumerate(a):
    b[t - 1] = i  # Store the index of each element in b

# Initialize a counter for the final result
c = 0

# Iterate through the array b in reverse order
for k in b[::-1]:
    l = r = 1  # Initialize left and right sizes
    
    # Check if the left neighbor exists and is greater
    if k > 0 and a[k - 1] > a[k]:
        l += size[root(k - 1)]  # Add the size of the left component
        unite(k - 1, k)  # Unite the left neighbor with the current element
    
    # Check if the right neighbor exists and is greater
    if k + 1 < n and a[k + 1] > a[k]:
        r += size[root(k + 1)]  # Add the size of the right component
        unite(k + 1, k)  # Unite the right neighbor with the current element
    
    # Update the counter with the product of left size, right size, and the current element's value
    c += l * r * a[k]

# Print the final result
print(c)
