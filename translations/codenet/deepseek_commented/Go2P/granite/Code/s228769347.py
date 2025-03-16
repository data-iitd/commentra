
import sys
from bisect import bisect_left

def main():
    fp = sys.stdin
    wfp = sys.stdout

    # Check if file paths are provided as command-line arguments.
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    n = int(fp.readline())
    ll = list(map(int, fp.readline().split()))

    ll.sort()

    ans = 0

    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            m = bisect_left(ll, ll[i] + ll[j])
            ans += m - (j + 1)

    print(ans, file=wfp)

if __name__ == "__main__":
    main()

