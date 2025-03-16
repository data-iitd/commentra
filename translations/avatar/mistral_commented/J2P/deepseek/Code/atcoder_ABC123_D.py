import sys

# Reading the size of the array x from the standard input stream
x = list(map(int, sys.stdin.readline().split()))

# Reading the elements of the array x from the standard input stream
max_val = 0
x_values = []
for i in range(3):
    val = int(sys.stdin.readline().strip())
    x_values.append(val)
    max_val = max(max_val, val)

# Reading the integer k from the standard input stream
k = int(sys.stdin.readline().strip())

# Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
a = [[] for _ in range(3)]
for i in range(3):
    a[i] = list(map(int, sys.stdin.readline().split()))
    a[i].sort()

# Finding all such sums and adding them to the list ans
ans = []
for i in range(x_values[0]):
    for j in range(x_values[1]):
        for m in range(x_values[2]):
            if (i + 1) * (j + 1) * (m + 1) <= k:
                tmp = a[0][-i-1] + a[1][-j-1] + a[2][-m-1]
                ans.append(tmp)

# Sorting the list ans in ascending order
ans.sort()

# Printing the last k elements of the list ans
for i in range(k):
    print(ans[-i-1])
