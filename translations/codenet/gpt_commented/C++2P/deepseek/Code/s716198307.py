n = int(input())
a = list(map(int, input().split()))

avg = sum(a) / n
s = min(abs(x - avg) for x in a)
ans = min(range(n), key=lambda i: abs(a[i] - avg))

print(ans)
