

n = int(input())
while n:
    d = [[] for _ in range(33)]
    v = [0]*n
    for i in range(n):
        name, m = input().split()
        m = int(m)
        for j in range(m):
            a = int(input())
            v[i] += n - len(d[a])
            for k in range(len(d[a])):
                v[d[a][k]] -= 1
            d[a].append(i)
    v = list(zip(v, range(n)))
    v.sort()
    print(v[-1][0], end=' ')
    print(v[-1][1])
    n = int(input())

