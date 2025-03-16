
N = int(input())
P = list(map(int, input().split()))
mem = [0] * (N + 1)
for i in range(N):
    mem[P[i]] = i + 1

maxcnt = 1
cnt = 1
for i in range(1, N):
    if mem[i] < mem[i + 1]:
        cnt += 1
    else:
        maxcnt = max(maxcnt, cnt)
        cnt = 1

print(N - maxcnt)
