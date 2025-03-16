# Importing sys module for reading input from standard input.
import sys

# Function to solve the problem
def solve(N: int, M: int, Q: int, a: List[int], b: List[int], c: List[int], d: List[int]):
    # Initialize result to 0
    res = 0

    # Helper function to calculate the answer recursively
    def rec(A):
        # Nonlocal variable to update the result from the recursive calls
        nonlocal res

        # Base case: if all elements of A are placed, calculate the answer
        if len(A) == N:
            ans = 0
            for i in range(Q):
                # Check if the condition is satisfied
                if A[b[i] - 1] - A[a[i] - 1] == c[i]:
                    ans += d[i]
            # Update the result with the maximum answer
            res = max(res, ans)
            return

        # Recursive call: try placing elements from last_max to M
        last_max = 1 if len(A) == 0 else A[-1]
        for i in range(last_max, M + 1):
            rec(A + [i])

    # Call the helper function with an empty list
    rec([])

    # Print the result
    print(res)

# Main function to read input and call the solve function
def main():
    # Function to generate tokens from standard input
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Read input tokens
    tokens = iterate_tokens()

    # Read number of test cases
    N = int(next(tokens))

    # Read number of elements in the array and number of queries
    M = int(next(tokens))
    Q = int(next(tokens))

    # Read the arrays a, b, c, and d
    a = [int()] * Q
    b = [int()] * Q
    c = [int()] * Q
    d = [int()] * Q
    for i in range(Q):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
        c[i] = int(next(tokens))
        d[i] = int(next(tokens))

    # Call the solve function with the given input
    solve(N, M, Q, a, b, c, d)

# Run the main function if the script is executed directly
if __name__ == '__main__':
    main()
