
n, m = map(int, input().split())
x = [0] * 31
for _ in range(n):
  k, *a = map(int, input().split())
  for i in a:
    x[i] += 1
ans = sum(1 for i in x if i == n)
print(ans)
