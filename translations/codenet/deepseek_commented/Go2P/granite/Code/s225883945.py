
import sys

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # Set the first element of `a` to 0 to avoid unused variable error.
    a[0] = 0

    sum = k
    ans = 1
    # Loop to increment `sum` and `ans` until `sum` is less than `n`.
    while sum < n:
        sum = sum - 1 + k
        ans += 1
    print(ans)

if __name__ == "__main__":
    main()

