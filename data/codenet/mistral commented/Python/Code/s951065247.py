N, A, B, C = map(int, input().split())  # Read input: N (number of elements), A, B, C (target values)
l = [int(input()) for i in range(N)]  # Read input: List of integers l

# Function definition: Depth-First Search (DFS) to find the minimum cost to reach target values A, B, C
def dfs(cur, a, b, c):
    
    # Base case: If we have reached the end of the list, calculate the cost and return it
    if cur == N:
        return abs(A - a) + abs(B - b) + abs(C - c) - 30 if min(a, b, c) > 0 else 10 ** 9

    # Recursive case: Calculate the cost if we don't add the current element
    no_add = dfs(cur + 1, a, b, c)

    # Recursive case: Calculate the cost if we add the current element to A
    add_a = dfs(cur + 1, a + l[cur], b, c) + 10

    # Recursive case: Calculate the cost if we add the current element to B
    add_b = dfs(cur + 1, a, b + l[cur], c) + 10

    # Recursive case: Calculate the cost if we add the current element to C
    add_c = dfs(cur + 1, a, b, c + l[cur]) + 10

    # Return the minimum cost among all the possibilities
    return min(no_add, add_a, add_b, add_c)

# Call the DFS function with initial values: A = 0, B = 0, C = 0
print(dfs(0, 0, 0, 0))