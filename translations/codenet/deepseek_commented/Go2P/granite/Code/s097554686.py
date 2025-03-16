

n, t = map(int, input().split())
mem = [0] * (t + 1)
ans = 0

for _ in range(n):
    l, r = map(int, input().split())
    mem[l] += 1
    mem[r] -= 1

for i in range(1, t + 1):
    mem[i] += mem[i - 1]
    ans = max(ans, mem[i])

print(ans)

