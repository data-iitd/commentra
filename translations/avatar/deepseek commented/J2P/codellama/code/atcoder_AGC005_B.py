import array
import sys

# Reading the input
N = int(sys.stdin.readline())
a = array.array('i', map(int, sys.stdin.readline().split()))

# Initializing arrays to store the distances to the nearest smaller elements
leftl = array.array('i', [0] * N)
rightl = array.array('i', [0] * N)

# Using a deque to find the nearest smaller element to the right
que = []
index = 0
while index < N:
    while que and a[que[-1]] > a[index]:
        ind = que.pop()
        rightl[ind] = index - ind - 1
    que.append(index)
    index += 1
while que:
    ind = que.pop()
    rightl[ind] = N - ind - 1

# Using a deque to find the nearest smaller element to the left
index = N - 1
while index >= 0:
    while que and a[que[-1]] > a[index]:
        ind = que.pop()
        leftl[ind] = ind - index - 1
    que.append(index)
    index -= 1
while que:
    ind = que.pop()
    leftl[ind] = ind - index - 1

# Calculating the result by summing up the products
ans = 0
for i in range(N):
    ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)

# Printing the result
print(ans)

