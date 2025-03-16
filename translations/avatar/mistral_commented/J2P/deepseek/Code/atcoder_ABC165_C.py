import sys

# Declaring and initializing four integer arrays a, b, c, and d to None
a = None
b = None
c = None
d = None

# Declaring and initializing two integer variables n and m to zero
n = 0
m = 0

# Declaring and initializing an integer variable q to zero
q = 0

# Declaring and initializing a long variable ans to a very large negative number
ans = -100

def dfs(lst):
    global ans
    if len(lst) == n:
        score = 0
        for i in range(q):
            if lst[b[i]] - lst[a[i]] == c[i]:
                score += d[i]
        ans = max(ans, score)
        return

    if lst:
        for num in range(lst[-1], m + 1):
            lst.append(num)
            dfs(lst)
            lst.pop()
    else:
        for num in range(1, m + 1):
            lst.append(num)
            dfs(lst)
            lst.pop()

# Reading the input from stdin
input_data = sys.stdin.readline().strip().split()
n = int(input_data[0])
m = int(input_data[1])
q = int(input_data[2])

# Allocating memory for the arrays a, b, c, and d
a = [0] * q
b = [0] * q
c = [0] * q
d = [0] * q

# Reading the integers from stdin and storing them in arrays a, b, c, and d
for i in range(q):
    a[i], b[i], c[i], d[i] = map(int, sys.stdin.readline().strip().split())
    a[i] -= 1
    b[i] -= 1

# Calling the recursive function dfs with an empty list as an argument
dfs([])

# Printing the value of the long variable ans to stdout
print(ans)
