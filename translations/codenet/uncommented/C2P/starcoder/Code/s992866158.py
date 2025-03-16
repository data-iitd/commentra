n, k = map(int, input().split())
cnt = 0
while n:
    h = int(input())
    if h >= k:
        cnt += 1
    n -= 1
print(cnt)
# 