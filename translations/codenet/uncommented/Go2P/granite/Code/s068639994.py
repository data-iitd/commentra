
import sys
import bisect

def main():
    n = int(input())
    ls = list(map(int, input().split()))
    ls_rev = ls[:]
    ls.sort()
    ls_rev.sort(reverse=True)

    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
            x, y = q - p, q + p

            l = bisect.bisect_left(ls, x)
            r = n - bisect.bisect_left(ls_rev, y)

            sum = r - l
            if i >= l and i <= r:
                sum -= 1
            if j >= l and j <= r:
                sum -= 1
            sum = max(0, sum)
            ans += sum

    ans //= 3
    print(ans)

if __name__ == '__main__':
    main()

