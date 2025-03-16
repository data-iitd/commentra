# Step 1: Read the number of bamboo pieces (N), and the target lengths for the three sticks (A, B, C).
N, A, B, C = map(int, input().split())

# Step 2: Read the lengths of the N bamboo pieces.
l = [int(input()) for i in range(N)]

# Step 3: Define the depth-first search (DFS) function to explore different combinations of bamboo lengths.
def dfs(cur, a, b, c):
    # Step 4: Check if the current index has reached the end of the list.
    if cur == N:
        # Step 5: Calculate the penalty if sticks A, B, and C are formed.
        return abs(A - a) + abs(B - b) + abs(C - c) - 30 if min(a, b, c) > 0 else 10 ** 9
    
    # Step 6: Explore the three options: not adding the current bamboo length, adding it to stick A, B, or C.
    no_add = dfs(cur + 1, a, b, c)
    add_a = dfs(cur + 1, a + l[cur], b, c) + 10
    add_b = dfs(cur + 1, a, b + l[cur], c) + 10
    add_c = dfs(cur + 1, a, b, c + l[cur]) + 10

    # Step 7: Return the minimum penalty among the options.
    return min(no_add, add_a, add_b, add_c)

# Step 8: Print the result of the DFS function starting from index 0 with initial stick lengths of 0 for A, B, and C.
print(dfs(0, 0, 0, 0))
