
import sys

# Macros for convenience
def sz(a): return len(a)
def all(x): return x.begin(), x.end()
def pb push_back
def endl '\n'
def watch(x): print(f"{x} : {x}")

# Fast input/output
sys.stdin, sys.stdout = open('input.txt', 'r'), open('output.txt', 'w')

# Type definitions for ease of use
int = int
ll = int
vi = list
vvi = list
ii = tuple

# Constants for limits and modulo
N = 200001
K = 2000001
MOD = 100000007
INF = 100000005
INF64 = 2e18

# Function to solve the problem
def solve():
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

# Uncomment the following lines for file input/output during local testing
# if __name__ == "__main__":
#     input = open('input.txt', 'r')
#     sys.stdout = open('output.txt', 'w')

t = 1 # Variable to hold the number of test cases
# t = int(input()) # Uncomment to read the number of test cases
for _ in range(t):
    solve() # Call the solve function for each test case

Translate the above Python code to Java and end with comment "