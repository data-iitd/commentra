
import sys

def solve(N: int, M: int, Q: int, a: "List[int]", b: "List[int]", c: "List[int]", d: "List[int]"):
    res = 0  # Initialize the result variable to store the maximum score

    # Define the recursive function to generate sequences
    def rec(A):
        nonlocal res  # Access the res variable from the outer scope
        if len(A) == N:  # If the sequence length is equal to N
            ans = 0  # Initialize the answer for this sequence
            for i in range(Q):  # Iterate over all constraints
                if A[b[i] - 1] - A[a[i] - 1] == c[i]:  # Check if the constraint is satisfied
                    ans += d[i]  # Add the value of the constraint to the answer
            res = max(res, ans)  # Update the result with the maximum score
            return
        last_max = 1 if len(A) == 0 else A[-1]  # Determine the starting point for the next number
        for i in range(last_max, M + 1):  # Generate the next number in the sequence
            rec(A + [i])

    rec([])  # Start the recursive function with an empty list
    print(res)  # Print the result
    return

def main():
    def iterate_tokens():
        for line in sys.stdin:  # Read input line by line
            for word in line.split():  # Split the line into words
                yield word

    tokens = iterate_tokens()
    N = int(next(tokens))  # Read the value of N
    M = int(next(tokens))  # Read the value of M
    Q = int(next(tokens))  # Read the value of Q
    a = [int(next(tokens)) for _ in range(Q)]  # Read the list a
    b = [int(next(tokens)) for _ in range(Q)]  # Read the list b
    c = [int(next(tokens)) for _ in range(Q)]  # Read the list c
    d = [int(next(tokens)) for _ in range(Q)]  # Read the list d
    solve(N, M, Q, a, b, c, d)  # Call the solve function with the input values

if __name__ == '__main__':
    main()

