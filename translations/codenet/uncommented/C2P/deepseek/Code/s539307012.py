n, x, min_val = map(int, input().split())
x -= min_val
for _ in range(n - 1):
    m = int(input())
    x -= m
    if min_val > m:
        min_val = m
print(n + x // min_val)
