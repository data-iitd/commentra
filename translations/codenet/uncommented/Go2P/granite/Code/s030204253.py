
n = int(input())
a = list(map(float, input().split()))
for _ in range(n-1):
    a.sort()
    na = []
    for i in range(2, len(a)):
        na.append(a[i])
    na.append((a[0]+a[1])/2)
    a = na
print(a[0])
