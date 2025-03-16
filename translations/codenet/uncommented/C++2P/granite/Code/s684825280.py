
n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = [0] * (100000 * 2 + 13)
for x in a:
    cnt[x] += 1
a = [cnt[i] for i in range(len(cnt)) if cnt[i] > 0]
a.sort()
m = len(a) - k
ans = sum(a[:m])
print(ans)
