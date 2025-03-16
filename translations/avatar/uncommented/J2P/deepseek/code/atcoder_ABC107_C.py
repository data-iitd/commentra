import sys

def main():
    n, k = map(int, sys.stdin.readline().split())
    s = list(map(int, sys.stdin.readline().split()))

    if k == 1:
        ans = min(abs(x) for x in s)
        print(ans)
    elif n - k != 0:
        ans = float('inf')
        for i in range(n - k + 1):
            min_val = s[i]
            max_val = s[i + k - 1]
            if min_val < 0 and max_val > 0:
                temp = min(2 * (-min_val) + max_val, -min_val + 2 * max_val)
            else:
                temp = max(abs(min_val), abs(max_val))
            ans = min(ans, temp)
        print(ans)
    else:
        min_val = s[0]
        max_val = s[-1]
        if min_val < 0 and max_val > 0:
            print(min(2 * (-min_val) + max_val, -min_val + 2 * max_val))
        else:
            print(max(abs(min_val), abs(max_val)))

if __name__ == "__main__":
    main()
