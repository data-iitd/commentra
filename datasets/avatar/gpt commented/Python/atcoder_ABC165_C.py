import sys

def solve(N: int, M: int, Q: int, a: "List[int]", b: "List[int]", c: "List[int]", d: "List[int]"):
    # Initialize the result variable to store the maximum score
    res = 0
    
    # Recursive function to explore combinations of numbers
    def rec(A):
        nonlocal res  # Allow access to the outer variable 'res'
        
        # Base case: if the length of A equals N, calculate the score
        if len(A) == N:
            ans = 0
            # Check each query to see if it contributes to the score
            for i in range(Q):
                if A[b[i] - 1] - A[a[i] - 1] == c[i]:
                    ans += d[i]  # Add the score from the query if it matches
            # Update the maximum score found
            res = max(res, ans)
            return
        
        # Determine the starting point for the next number to be added
        last_max = 1 if len(A) == 0 else A[-1]
        
        # Iterate through possible values to add to the combination
        for i in range(last_max, M + 1):
            rec(A + [i])  # Recursively call with the new number added to A
    
    # Start the recursive exploration with an empty list
    rec([])
    
    # Print the maximum score found
    print(res)
    return

def main():
    # Generator function to iterate through input tokens
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    
    tokens = iterate_tokens()
    
    # Read the values of N, M, and Q from input
    N = int(next(tokens))
    M = int(next(tokens))
    Q = int(next(tokens))
    
    # Initialize lists to hold the query parameters
    a = [int()] * Q
    b = [int()] * Q
    c = [int()] * Q
    d = [int()] * Q
    
    # Read the query parameters from input
    for i in range(Q):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
        c[i] = int(next(tokens))
        d[i] = int(next(tokens))
    
    # Call the solve function with the parsed input
    solve(N, M, Q, a, b, c, d)

# Entry point of the script
if __name__ == '__main__':
    main()
