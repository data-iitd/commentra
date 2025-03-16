
import array
import sys

# Reading the input from the console
N = int(input())
a = array.array('i', map(int, input().split()))

# Creating two arrays to store the length of the left and right segments for each element
leftl = array.array('i', [0] * N)
rightl = array.array('i', [0] * N)

# Creating a double ended queue to implement two stacks
que = []

# Finding the length of the left and right segments for each element using two stacks
index = 0
while index < N:
    while que and a[que[-1]] > a[index]:
        ind = que.pop()
        rightl[ind] = index - ind - 1
    que.append(index)
    index += 1

# Calculating the length of the right segment for the last element
while que:
    ind = que.pop()
    rightl[ind] = N - ind - 1

# Finding the length of the left segments for each element using two stacks in reverse order
index = N - 1
while index >= 0:
    while que and a[que[-1]] > a[index]:
        ind = que.pop()
        leftl[ind] = ind - index - 1
    que.append(index)
    index -= 1

# Calculating the length of the left segment for the first element
while que:
    ind = que.pop()
    leftl[ind] = ind - index - 1

# Calculating the answer by multiplying the element, left segment length, and right segment length for each element
ans = 0
for i in range(N):
    ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)

# Printing the final answer
print(ans)

