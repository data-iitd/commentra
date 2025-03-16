

n, m = map(int, input().split())
q1 = list(map(int, input().split()))
q2 = list(range(1, n+1))
ans = 0

while q1:
    if q1[0] <= m:
        q1.pop(0)
        ans = q2.pop(0)
    else:
        x = q1.pop(0)
        val = x - m
        q1.append(val)
        val2 = q2.pop(0)
        q2.append(val2)

print(ans)
