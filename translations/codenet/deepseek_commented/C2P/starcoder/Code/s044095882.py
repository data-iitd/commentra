# <START-OF-CODE>

n = int(input())
a = [int(x) for x in input().split()]
count = [0] * n

for i in range(1, n):
    count[a[i]-1] += 1

for i in range(n):
    print(count[i])

# 