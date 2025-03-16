
import sys

N = int(input())
A = list(map(int, input().split()))

sum_A = sum(A)
wa = N * (N + 1) // 2

if sum_A % wa!= 0:
    print("NO")
    sys.exit()

shou = sum_A // wa
sa = [A[(i + 1) % N] - A[i] - shou for i in range(N)]

for i in range(N - 1):
    if sa[i] <= 0 and sa[i] % N!= 0:
        print("NO")
        sys.exit()

print("YES")

