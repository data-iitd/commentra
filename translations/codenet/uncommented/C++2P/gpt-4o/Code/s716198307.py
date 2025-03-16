n = int(input())
a = list(map(int, input().split()))
avg = sum(a) / n
s = abs(a[0] - avg)
ans = 0

for i in range(1, n):
    if s > abs(a[i] - avg):
        s = abs(a[i] - avg)
        ans = i

print(ans)
# <END-OF-CODE>
