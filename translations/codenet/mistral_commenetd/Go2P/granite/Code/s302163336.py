

n, m = map(int, input().split())
h = list(map(int, input().split()))
good = [True] * n
for _ in range(m):
    a, b = map(int, input().split())
    if h[a - 1] > h[b - 1]:
        good[b - 1] = False
    elif h[a - 1] < h[b - 1]:
        good[a - 1] = False
    else:
        good[a - 1] = False
        good[b - 1] = False
print(sum(good))
