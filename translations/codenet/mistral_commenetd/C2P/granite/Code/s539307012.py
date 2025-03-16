
n, x, min = map(int, input().split())
x -= min
for i in range(1, n):
    m = int(input())
    x -= m
    if min > m:
        min = m
print(n + x // min)

