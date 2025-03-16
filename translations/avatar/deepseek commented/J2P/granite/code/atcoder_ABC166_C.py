
import sys

N, M = map(int, input().split())
H = list(map(int, input().split()))
ans = [True] * N

for _ in range(M):
    temp1, temp2 = map(int, input().split())
    temp1 -= 1
    temp2 -= 1
    if H[temp1] < H[temp2]:
        ans[temp1] = False
    elif H[temp1] > H[temp2]:
        ans[temp2] = False
    else:
        ans[temp1] = False
        ans[temp2] = False

print(sum(ans))
