import sys

# Function to update the value of 'a' to 'b' if 'b' is less than 'a'
def chmin(a, b):
    if a > b:
        a = b  # Update 'a' to 'b'
        return True  # Indicate that 'a' was changed
    return False  # Indicate that 'a' was not changed

# Function to update the value of 'a' to 'b' if 'b' is greater than 'a'
def chmax(a, b):
    if a < b:
        a = b  # Update 'a' to 'b'
        return True  # Indicate that 'a' was changed
    return False  # Indicate that 'a' was not changed

# Constants for infinity and modulo operations
INF = (1 << 30) - 1  # Integer infinity
INFLL = (1LL << 61) - 1  # Long long infinity
MOD = 1000000007  # Modulo value for calculations

# Macros for convenience in iterating and accessing containers
ALL = lambda a: a.begin(), a.end()  # Macro to access all elements of a container
rALL = lambda a: a.rbegin(), a.rend()  # Macro to access all elements in reverse order
FOR = lambda i, a, b: range(a, b)  # Macro for a for-loop from a to b
REP = lambda i, n: range(n)  # Macro for a for-loop from 0 to n

# Main function
def main():
    input = sys.stdin.readline
    # Untie cin from cout for faster input
    sys.stdin.tie(None)
    # Disable synchronization with C I/O for performance
    sys.stdin.sync_with_stdio(False)

    # Declare variables for input
    A, B, C, K = map(int, input().split())

    # Check if the sum of A and B is greater than or equal to K
    if A + B >= K:
        # If true, output the minimum of A and K
        print(min(A, K))
    else:
        # If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
        print(A - (K - (A + B)))

# Call the main function
main()
