
# Python 3 program to solve the problem

# Function to solve the problem
def solve ():
    ans = 0 # Initialize the answer variable
    n = int(input()) # Read the number of nodes

    # Calculate the contribution of each node to the answer
    for i in range(1, n+1):
        ans += i * (n - i + 1) # Contribution of node i

    # Adjust the answer based on the edges between nodes
    for i in range(1, n):
        u, v = map(int, input().split()) # Read the edge connecting nodes u and v
        a = max(u, v) # Determine the maximum node
        b = min(u, v) # Determine the minimum node
        ans -= b * (n - a + 1) # Subtract the contribution of the edge

    # Output the final answer
    print(ans)

if __name__ == '__main__':
    solve() # Call the solve function for each test case

# 