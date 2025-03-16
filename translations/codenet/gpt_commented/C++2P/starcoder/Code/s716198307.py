n = int(input())
a = [int(x) for x in input().split()]
avg = sum(a) / n
s = min(abs(x - avg) for x in a)
ans = a.index(min(a))
print(ans)

