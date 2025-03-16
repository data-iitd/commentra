
n = int(input())
while n:
    v = []
    d = [[] for _ in range(33)]
    for _ in range(n):
        m = int(input())
        s = input()
        for a in map(int, input().split()):
            v.append((n - len(d[a]), s))
            for i in d[a]:
                v[i] = (v[i][0] - 1, v[i][1])
            d[a].append(_)
    v.sort()
    print(v[0][0], v[0][1])
    n = int(input())