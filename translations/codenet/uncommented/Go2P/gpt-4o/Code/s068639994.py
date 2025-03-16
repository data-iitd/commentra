import sys
import bisect

def main_fn():
    n = get_int()
    ls = get_int_slice(n)
    ls_rev = sorted(ls, reverse=True)

    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
            x, y = q - p, q + p

            l = bisect.bisect_right(ls, x)
            r = n - bisect.bisect_left(ls_rev, y)

            sum_count = r - l
            if l <= i <= r - 1:
                sum_count -= 1
            if l <= j <= r - 1:
                sum_count -= 1
            sum_count = max(0, sum_count)
            ans += sum_count

    ans //= 3
    puts(ans)

def get_int():
    return int(sys.stdin.readline().strip())

def get_int_slice(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def puts(*args):
    print(*args)

if __name__ == "__main__":
    main_fn()
# <END-OF-CODE>
