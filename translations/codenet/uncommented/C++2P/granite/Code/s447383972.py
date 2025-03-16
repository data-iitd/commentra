
n = int(input())
a = list(map(int, input().split()))
a.sort()
q = []
for i in range(n):
    if i == n - 1 or a[i]!= a[i + 1]:
        q.append(a[i])
print(q[-1] * q[-2])
