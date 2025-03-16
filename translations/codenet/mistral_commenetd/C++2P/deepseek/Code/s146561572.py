import sys

# Function to solve the problem
def solve():
    # Initialize answer to 0
    ans = 0
    
    # Read input for number of nodes n
    n = int(input())
    
    # Calculate contribution of each node to the answer
    for i in range(1, n + 1):
        # Contribution of i-th node is i * (n-i+1)
        ans += i * (n - i + 1)
    
    # Subtract contribution of edges
    for _ in range(n - 1):
        # Read input for two nodes u and v
        u, v = map(int, input().split())
        
        # Find maximum and minimum of u and v
        a = max(u, v)
        b = min(u, v)
        
        # Subtract contribution of edge (u,v) from the answer
        ans -= b * (n - a + 1)
    
    # Print the answer
    print(ans)

# Main function to read input and call solve function
if __name__ == "__main__":
    # Set number of test cases to 1 for simplicity
    t = 1
    
    # Solve the problem for each test case
    while t > 0:
        solve()
        t -= 1
