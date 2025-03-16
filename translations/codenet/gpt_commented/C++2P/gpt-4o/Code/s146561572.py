import sys

# Fast input/output
input = sys.stdin.read
def solve():
    ans = 0  # Initialize the answer variable
    n = int(input().strip())  # Read the number of nodes

    # Calculate the contribution of each node to the answer
    for i in range(1, n + 1):
        ans += i * (n - i + 1)  # Contribution of node i

    # Adjust the answer based on the edges between nodes
    for _ in range(1, n):
        u, v = map(int, input().strip().split())  # Read the edge connecting nodes u and v
        a = max(u, v)  # Determine the maximum node
        b = min(u, v)  # Determine the minimum node
        ans -= b * (n - a + 1)  # Subtract the contribution of the edge

    # Output the final answer
    print(ans)

if __name__ == "__main__":
    # Uncomment the following lines for file input/output during local testing
    # sys.stdin = open("input.txt", "r")
    # sys.stdout = open("output.txt", "w")

    t = 1  # For now, we will just run one test case
    for _ in range(t):
        solve()  # Call the solve function for each test case

# <END-OF-CODE>
