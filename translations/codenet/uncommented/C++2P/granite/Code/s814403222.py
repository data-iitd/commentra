
n = int(input())
while n:
    m = int(input())
    d = [[] for i in range(33)]
    v = [[0,""] for i in range(n)]
    for i in range(n):
        v[i][1] = input()
        m = int(input())
        for j in range(m):
            a = int(input())
            v[i][0] += n - len(d[a])
            for k in range(len(d[a])):
                v[d[a][k]][0] -= 1
            d[a].append(i)
    v.sort()
    print(v[0][0],v[0][1])
    n = int(input())