
import sys

N = int(input())
a = list(map(int, input().split()))
ind_a = [0] * N
for i in range(N):
    ind_a[a[i] - 1] = i

used_inds = set()
ans = 0
for i in range(N):
    left_border = -1
    right_border = N
    cur_ind = ind_a[i]
    left_it = next((x for x in used_inds if x < cur_ind), None)
    right_it = next((x for x in used_inds if x > cur_ind), None)
    if left_it is not None:
        left_border = left_it
    if right_it is not None:
        right_border = right_it
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)
    used_inds.add(cur_ind)

print(ans)

