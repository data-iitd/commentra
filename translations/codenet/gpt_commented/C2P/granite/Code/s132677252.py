
import sys

# Define types for 32-bit and 64-bit integers
i32 = int
i64 = int

# Define a constant for modulo operations
mod = 1000000007

# Function to compute modular exponentiation
def mod_pow (r, n):
    t = 1 # Result variable
    s = r # Base
    # Loop until the exponent is zero
    while n > 0:
        if n & 1: t = (t * s) % mod # If n is odd, multiply the result by the base
        s = (s * s) % mod # Square the base
        n >>= 1 # Divide n by 2
    return t # Return the result

# Structure to represent a node in dynamic programming
class Node:
    def __init__ (self, one, zero):
        self.one = one # Count of paths ending with 1
        self.zero = zero # Count of paths ending with 0

# Function to merge multiple dp nodes
def merge (a, n):
    one = 0 # Initialize count of paths ending with 1
    zero = 1 # Initialize count of paths ending with 0
    total = 1 # Initialize total paths
    # Iterate through the nodes to merge their counts
    for i in range (n):
        one = (one * a[i].zero + zero * a[i].one) % mod # Update count of paths ending with 1
        zero = zero * a[i].zero % mod # Update count of paths ending with 0
        total = total * (a[i].zero + a[i].one) % mod # Update total paths
    return Node (one, (total + mod - one) % mod) # Return merged node

# Define a type for deque values
class DequeVal:
    def __init__ (self, one, zero):
        self.one = one # Count of paths ending with 1
        self.zero = zero # Count of paths ending with 0

# Structure to represent a deque (double-ended queue)
class Deque:
    def __init__ (self):
        self.array = [] # Initialize array to store deque values
        self.front = 0 # Initialize front index
        self.last = 0 # Initialize last index
        self.mask = 0 # Initialize mask for circular indexing

    def get_size (self):
        return (self.last + (~self.front + 1)) & self.mask # Calculate the size using circular indexing

    def reallocate (self):
        # Allocate a new array with double the size
        new_array = [None] * (2 * (self.mask + 1))
        k = 0 # Index for the new array
        # Copy elements from the old array to the new array
        for i in range (self.front, self.last):
            new_array[k] = self.array[i]
            k += 1
        self.array = new_array # Update the deque's array to the new array
        self.front = 0 # Reset front index
        self.last = k # Update last index
        self.mask = 2 * self.mask + 1 # Update the mask for the new size

    def get_at (self, x):
        return self.array[(self.front + x) & self.mask] # Return the value using circular indexing

    def assign_at (self, x, v):
        self.array[(self.front + x) & self.mask] = v # Assign the value using circular indexing

    def push_front (self, v):
        # Check if the deque is full
        if self.get_size() == len (self.array):
            self.reallocate () # Reallocate if full
        self.front = (self.front + self.mask) & self.mask # Move front index backwards
        self.array[self.front] = v # Assign the value at the front

# Function to run the algorithm
def run ():
    n = int (input ()) # Read the number of vertices
    p = [0] * (n + 1) # Allocate memory for parent array
    depth = [0] * (n + 1) # Allocate memory for depth array
    cnt = [0] * (n + 1) # Allocate memory for count array
    cnt[0] = 1 # Initialize count for depth 0
    g = {} # Create an empty graph
    # Read edges and build the graph
    for i in range (1, n + 1):
        p[i] = int (input ()) # Read parent for vertex i
        if p[i] not in g:
            g[p[i]] = [] # Initialize an empty list for the parent vertex
        g[p[i]].append (i) # Add the current vertex as a child of the parent
        depth[i] = depth[p[i]] + 1 # Update depth of the current vertex
        cnt[depth[i]] += 1 # Increment count for the current depth
    # Allocate memory for dynamic programming arrays
    dp = {} # Create an empty dictionary for dp arrays
    child = {} # Create an empty dictionary for child deques
    lst = [None] * (n + 1) # Allocate memory for the lst array
    # Process vertices in reverse order
    for i in range (n, -1, -1):
        v = i # Current vertex
        # If the vertex has no outgoing edges
        if v not in g:
            dp[v] = Deque () # Create a new deque for this vertex
            dp[v].push_front (Node (1, 1)) # Initialize with base case
            continue # Move to the next vertex
        len = 0 # Initialize length of child deques
        # Collect child deques for the current vertex
        for u in g[v]:
            if u not in dp:
                dp[u] = Deque () # Create a new deque for the child vertex
                dp[u].push_front (Node (1, 1)) # Initialize with base case
            child[u] = dp[u] # Store the child deque
            len += 1 # Increment the length of child deques
        # If there are multiple child deques, merge them
        if len > 1:
            child_list = list (child.values ()) # Convert child deques to a list
            child_list.sort (key = lambda x: x.get_size ()) # Sort child deques by size
            # Merge the child deques
            for d in range (child_list[0].get_size ()):
                j = 0
                for u in child:
                    if d < child[u].get_size ():
                        lst[j] = child[u].get_at (d) # Get nodes from child deques
                        j += 1
                child_list[0].assign_at (d, merge (lst, j)) # Merge and assign to the first child
            # Free the other child deques
            for u in child:
                if u!= child_list[0]:
                    del dp[u] # Free the memory allocated for the child deque
        dp[v] = child_list[0] # Assign the merged deque to the current vertex
        dp[v].push_front (Node (1, 1)) # Add the base case to the front
    ans = 0 # Initialize the final answer variable
    # Calculate the final answer based on the dp values
    for d in range (n + 1):
        ans = (ans + (mod_pow (2, n + 1 - cnt[d]) * dp[0].get_at (d).one) % mod) % mod # Update the final answer
    print (ans) # Print the final answer

# Main function to execute the program
def main ():
    run () # Call the run function
    return 0 # Return success

# Execute the main function
if __name__ == "__main__":
    sys.exit (main ())

