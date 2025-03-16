
n = int(input())
a = list(map(int, input().split()))
print(a[-1], end = " ")
for i in range(n-2, -1, -1):
    print(a[i], end = " ")
print()
