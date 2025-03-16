import sys

def main():
    N = int(input().strip())
    a = list(map(int, input().strip().split()))
    ind_a = [0] * N
    for i in range(N):
        ind_a[a[i] - 1] = i

    used_inds = set()
    ans = 0
    for i in range(N):
        cur_ind = ind_a[i]
        left_it = used_inds.bisect_left(cur_ind)
        right_it = used_inds.bisect_left(cur_ind + 1)

        if left_it == 0:
            left_border = -1
        else:
            if right_it == len(used_inds) or used_inds[right_it] > cur_ind:
                left_it -= 1
            left_border = used_inds[left_it]

        if right_it == len(used_inds):
            right_border = N
        else:
            right_border = used_inds[right_it]

        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((i + 1))

        used_inds.add(cur_ind)

    print(ans)

if __name__ == "__main__":
    main()
