# Read input values: N (number of elements), A, B, C (target values)
N, A, B, C = map(int, input().split())

# Read the list of integers from input
l = [int(input()) for i in range(N)]

# Define a recursive function to perform depth-first search (DFS)
def dfs(cur, a, b, c):
    # Base case: if we have considered all elements
    if cur == N:
        # Calculate the penalty based on the current sums and targets
        # Return a large value if any of a, b, c is zero, otherwise return the calculated penalty
        return abs(A - a) + abs(B - b) + abs(C - c) - 30 if min(a, b, c) > 0 else 10 ** 9
    
    # Recursive case: explore the option of not adding the current element
    no_add = dfs(cur + 1, a, b, c)
    
    # Explore the option of adding the current element to 'a'
    add_a = dfs(cur + 1, a + l[cur], b, c) + 10
    
    # Explore the option of adding the current element to 'b'
    add_b = dfs(cur + 1, a, b + l[cur], c) + 10
    
    # Explore the option of adding the current element to 'c'
    add_c = dfs(cur + 1, a, b, c + l[cur]) + 10

    # Return the minimum penalty from all options considered
    return min(no_add, add_a, add_b, add_c)

# Start the DFS with initial values of a, b, c set to 0 and print the result
print(dfs(0, 0, 0, 0))
