import sys

def next():
    return sys.stdin.readline().strip()

def next_int():
    return int(next())

def next_floats():
    return list(map(float, next().split()))

def next_ints(n):
    return [next_int() for _ in range(n)]

def main():
    n, k = next_int(), next_int()
    a = next_ints(n)
    a[0] = 0  # Set the first element of `a` to 0 to avoid unused variable error.

    sum = k
    ans = 1
    # Loop to increment `sum` and `ans` until `sum` is less than `n`.
    while sum < n:
        sum = sum - 1 + k
        ans += 1

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
