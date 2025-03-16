
# <START-OF-CODE>

n = int(input())

d = [1000000] * n

a = []

for i in range(n):
    u, k = map(int, input().split())
    for j in range(k):
        v, c = map(int, input().split())
        a.append((u, v, c))

def root(b):
    for i in range(n):
        d[i] = 1000000
    d[0] = 0
    flag = 1
    while flag!= 0:
        flag = 0
        for i in range(b):
            if a[i][2] + d[a[i][1]] < d[a[i][0]]:
                d[a[i][0]] = a[i][2] + d[a[i][1]]
                flag = 1

root(len(a))

for i in range(n):
    print(i, d[i])

# 