
import sys

N = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().split()]

ind_a = [0] * N
for i in range(N):
    ind_a[a[i] - 1] = i

used_inds = set()
ans = 0
for i in range(N):
    cur_ind = ind_a[i]
    left_border = -1
    right_border = N
    if cur_ind in used_inds:
        left_it = used_inds.lower_bound(cur_ind)
        right_it = used_inds.lower_bound(cur_ind + 1)
        if left_it!= used_inds.begin():
            left_it -= 1
        if right_it!= used_inds.end():
            right_border = *right_it
        if left_it!= used_inds.end():
            left_border = *left_it
    ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)
    used_inds.add(cur_ind)

print(ans)

