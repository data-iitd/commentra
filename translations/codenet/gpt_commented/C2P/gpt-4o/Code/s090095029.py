def main():
    # Read the number of nodes and edges from standard input
    n, m = map(int, input().split())
    
    # Initialize a list to track connections (r0) and set all values to False
    r0 = [False] * n
    
    # Initialize a list to store nodes connected to node n (r1) and a counter for it
    r1 = []
    
    # Process each edge input
    for _ in range(m):
        a, b = map(int, input().split())
        
        # Ensure a is the smaller node and b is the larger node
        if a > b:
            a, b = b, a
        
        # Mark the connection from node a to node b in r0
        if a == 1:
            r0[b - 1] = True  # If a is 1, mark b-1 as connected
        
        # If b is the last node (n), store a-1 in r1
        if b == n:
            r1.append(a - 1)  # Store a-1 in r1
    
    # Initialize a result variable to determine if a connection is possible
    res = False
    
    # Check if any of the nodes connected to node n are also connected to node 1
    for i in r1:
        if r0[i]:
            res = True  # If r0 at r1[i] is True, set res to True
    
    # Output the result based on the value of res
    print("POSSIBLE" if res else "IMPOSSIBLE")

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
