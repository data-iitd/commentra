import sys

# Function to read an integer from standard input
def read():
    return int(sys.stdin.readline().strip())

# Function to write an integer to standard output
def write(x):
    sys.stdout.write(str(x))

# Function to write an integer and a newline to standard output
def writeln(x):
    write(x)
    sys.stdout.write("\n")

# Initialize variables
n, m = 0, 0
fa = [0] * 100005
v = [0] * 200005

# Function to get the root of a tree
def get(x):
    if fa[x] == x:
        return x  # Base case: the root of the tree is itself
    f = get(fa[x])  # Recursively find the root of the tree
    v[x] += v[fa[x]]  # Update the depth of the nodes on the path from 'x' to the root
    fa[x] = f  # Update the father of 'x'
    return f

# Main function
def main():
    global n, m, fa, v
    # Read the number of vertices 'n' and edges 'm'
    n = read()
    m = read()
    # Initialize the trees for each vertex
    for i in range(1, n + 1):
        fa[i] = i
    # Process each edge
    for _ in range(m):
        # Read the left and right endpoints and the value 'vi' of the edge
        l = read()
        r = read()
        vi = read()
        # Find the roots of the trees of the left and right endpoints
        li = get(l)
        ri = get(r)
        # If the roots are different, update the depth of the right tree and its father
        if li != ri:
            v[ri] += vi - v[r] + v[l]  # Update the depth of the right tree
            fa[ri] = li  # Set the father of the right tree to the father of the left tree
        else:
            # If the roots are the same, check if the value of the edge is correct
            if v[r] - v[l] != vi:
                print("No")  # Output 'No' if the value is incorrect
                return  # Terminate the program
    # Output 'Yes' if all edges have the correct value
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
