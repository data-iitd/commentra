def main():
    import sys
    from sortedcontainers import SortedSet

    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    a = list(map(int, data[1:N+1]))
    
    ind_a = [0] * N
    for i in range(N):
        ind_a[a[i] - 1] = i

    used_inds = SortedSet()
    ans = 0
    for i in range(N):
        cur_ind = ind_a[i]
        
        left_border = -1 if not used_inds else used_inds[used_inds.bisect_left(cur_ind) - 1] if used_inds.bisect_left(cur_ind) > 0 else -1
        right_border = N if used_inds.bisect_left(cur_ind + 1) == len(used_inds) else used_inds[used_inds.bisect_left(cur_ind + 1)]
        
        ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

        used_inds.add(cur_ind)

    print(ans)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
