n = int(input())
a = [int(x) for x in input().split()]
avg = sum(a)/n
s = min(abs(a[i]-avg) for i in range(n))
ans = [i for i in range(n) if abs(a[i]-avg) == s][0]
print(ans)

