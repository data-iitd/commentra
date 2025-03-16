
N, K = map(int, input().split())
as = [0] * N
for i in range(K):
    d = int(input())
    for j in range(d):
        a = int(input())
        as[a-1] += 1
ans = 0
for a in as:
    if a == 0:
        ans += 1
print(ans)
