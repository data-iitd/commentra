from collections import defaultdict

while True:
    n = int(input())
    if n == 0:
        break

    v = [(0, "") for _ in range(n)]
    d = defaultdict(list)

    for i in range(n):
        m = int(input())
        v[i] = (0, input().strip())
        for _ in range(m):
            a = int(input())
            v[i] = (v[i][0] + n - len(d[a]), v[i][1])
            for k in d[a]:
                v[k] = (v[k][0] - 1, v[k][1])
            d[a].append(i)

    v.sort()
    print(v[0][0], v[0][1])

# <END-OF-CODE>
