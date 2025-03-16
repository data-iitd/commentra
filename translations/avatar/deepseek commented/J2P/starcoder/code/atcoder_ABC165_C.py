import sys

# Arrays to store input values
a = None
b = None
c = None
d = None

# Variables to store input values
n = 0
m = 0
q = 0

# Variable to store the maximum score
ans = -100

# Read values of n, m, and q
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
q = int(sys.stdin.readline())

# Initialize arrays to store the conditions
a = [0] * q
b = [0] * q
c = [0] * q
d = [0] * q

# Read the conditions into the arrays
for i in range(q):
    a[i] = int(sys.stdin.readline()) - 1 # Adjusting for 0-based index
    b[i] = int(sys.stdin.readline()) - 1 # Adjusting for 0-based index
    c[i] = int(sys.stdin.readline())
    d[i] = int(sys.stdin.readline())

# Start the DFS with an empty list
def dfs(list):
    # If the list size equals n, calculate the score and update ans
    if len(list) == n:
        score = 0
        for i in range(q):
            if list[b[i]] - list[a[i]] == c[i]:
                score += d[i]
        ans = max(ans, score)
        return

    # If the list is not empty, continue adding numbers from the last number in the list
    if len(list) > 0:
        for num in range(list[-1], m + 1):
            list.append(num)
            dfs(list)
            list.pop()
    else:
        # If the list is empty, start with numbers from 1 to m
        for num in range(1, m + 1):
            list.append(num)
            dfs(list)
            list.pop()

dfs([])

# Print the maximum score found
print(ans)

# 