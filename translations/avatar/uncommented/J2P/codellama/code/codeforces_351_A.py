import math
import sys

n = int(sys.stdin.readline())
arr = list(map(float, sys.stdin.readline().split()))
non_int = 0
sum_before = 0
sum = 0
for i in range(0, 2*n):
    num = arr[i]
    sum_before += num
    if num != math.floor(num):
        non_int += 1
    sum += math.floor(num)

max_sum = max(0, non_int - n) + sum
min_sum = min(n, non_int) + sum
ans = 0
if min_sum > sum_before:
    ans = min_sum - sum_before
elif max_sum < sum_before:
    ans = sum_before - max_sum
else:
    x = sum_before - math.floor(sum_before)
    ans = min(1 - x, x)

print(round(ans, 3))


