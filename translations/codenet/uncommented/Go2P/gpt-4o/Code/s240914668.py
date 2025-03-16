import sys

def next_int():
    return int(next_token())

def next_ints(n):
    return [next_int() for _ in range(n)]

def next_token():
    return next(tokens)

def main():
    global tokens
    tokens = iter(sys.stdin.read().split())
    
    n = next_int()
    a = next_ints(n)

    ans = 0
    i = 0
    while i < n:
        l, r = i, i + 1
        while r + 1 < n and (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0:
            r += 1
        ans += 1
        i = r

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
