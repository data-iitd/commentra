
while True:
    n = int(input())
    if n == 0:
        break
    v = [0]*n
    d = [[] for _ in range(33)]
    for i in range(n):
        name = input()
        m = int(input())
        for j in range(m):
            a = int(input())
            v[i] += n - len(d[a])
            for k in range(len(d[a])):
                v[d[a][k]] -= 1
            d[a].append(i)
    v = list(zip(v, [""]*n))
    v.sort(reverse=True)
    print(v[0][0], v[0][1])

