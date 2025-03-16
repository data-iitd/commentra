

def solve():
    # Initialize answer to 0
    ans = 0
    
    # Read input for number of nodes n
    n = int(input())
    
    # Calculate contribution of each node to the answer
    for i in range(1, n+1):
        # Contribution of i-th node is i * (n-i+1)
        ans += i * (n-i+1)
    
    # Subtract contribution of edges
    for i in range(1, n):
        # Read input for two nodes u and v
        u, v = map(int, input().split())
        
        # Find maximum and minimum of u and v
        a = max(u, v)
        b = min(u, v)
        
        # Subtract contribution of edge (u,v) from the answer
        ans -= b * (n-a+1)
    
    # Print the answer
    print(ans)

if __name__ == "__main__":
    t = 1  # Set number of test cases to 1 for simplicity
    
    # Solve the problem for each test case
    for _ in range(t):
        solve()

This should cover all the logical blocks in the code and provide suitable comments. Let me know if you need any further clarification or modification.