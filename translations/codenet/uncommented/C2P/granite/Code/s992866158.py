
n, k = map(int, input().split())
cnt = 0
for _ in range(n):
    h = int(input())
    if h >= k:
        cnt += 1
print(cnt)
