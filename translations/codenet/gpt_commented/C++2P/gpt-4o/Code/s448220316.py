import sys

# Function to read an integer from input
def read():
    return int(sys.stdin.readline().strip())

# Function to write an integer to output
def write(x):
    sys.stdout.write(str(x))

# Function to write an integer followed by a newline
def writeln(x):
    sys.stdout.write(str(x) + "\n")

# Global variables for number of nodes, edges, and other parameters
n, m = 0, 0
fa = []
v = []

# Function to find the representative of a set and update the value
def get(x):
    if x == fa[x]:
        return x
    f = get(fa[x])
    v[x] += v[fa[x]]
    fa[x] = f
    return f

def main():
    global n, m, fa, v
    n = read()  # Read number of nodes
    m = read()  # Read number of edges
    fa = list(range(n + 1))  # Initialize the parent array for union-find
    v = [0] * (n + 1)  # Initialize the value array

    # Process each edge
    for _ in range(m):
        l = read()  # Read left node
        r = read()  # Read right node
        vi = read()  # Read value to be assigned
        li = get(l)  # Find representative of left node
        ri = get(r)  # Find representative of right node

        # If they belong to different sets, union them
        if li != ri:
            v[ri] = vi - v[r] + v[l]  # Update the value for the new root
            fa[ri] = li  # Union the sets
        else:
            # If they are in the same set, check for consistency
            if v[r] - v[l] != vi:
                print("No")  # Inconsistent values
                return  # Exit the program

    print("Yes")  # All edges processed successfully

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
