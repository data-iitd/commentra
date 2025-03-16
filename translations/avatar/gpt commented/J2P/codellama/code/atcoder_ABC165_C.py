import sys

# Read the values of n, m, and q from input
n, m, q = map(int, sys.stdin.readline().split())

# Initialize arrays based on the number of queries (q)
a = [0] * q
b = [0] * q
c = [0] * q
d = [0] * q

# Read the query parameters into the arrays
for i in range(q):
    a[i], b[i], c[i], d[i] = map(int, sys.stdin.readline().split())

# Initialize variables for dimensions and result
ans = -100

# Start the depth-first search (DFS) to find the maximum score
def dfs(list):
    # Check if the current list has reached the required size (n)
    if len(list) == n:
        score = 0

        # Calculate the score based on the queries
        for i in range(q):
            # If the condition is met, add the corresponding value to the score
            score += (list[b[i]] - list[a[i]] == c[i]) * d[i]

        # Update the maximum score if the current score is higher
        global ans
        ans = max(ans, score)
        return

    # If the list is not empty, continue adding numbers from the last added number to m
    if list:
        for num in range(list[-1], m + 1):
            list.append(num)  # Add the current number to the list
            dfs(list)  # Recur with the updated list
            list.pop()  # Backtrack by removing the last number
    else:
        # If the list is empty, start adding numbers from 1 to m
        for num in range(1, m + 1):
            list.append(num)  # Add the current number to the list
            dfs(list)  # Recur with the updated list
            list.pop()  # Backtrack by removing the last number

# Start the depth-first search (DFS) to find the maximum score
dfs([])

# Output the maximum score found
print(ans)

