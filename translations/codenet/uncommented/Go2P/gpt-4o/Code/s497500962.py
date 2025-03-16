import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    R = next_int()
    G = next_int()
    B = next_int()
    N = next_int()

    ans = 0
    for x in range(N + 1):
        for y in range(N + 1):
            tmp = N - R * x - G * y
            if tmp >= 0 and tmp % B == 0:
                ans += 1

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
