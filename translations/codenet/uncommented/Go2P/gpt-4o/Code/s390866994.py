import sys

def out(*args):
    print(*args)

def get_int():
    return int(sys.stdin.readline().strip())

def get_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    N, C, K = get_ints()
    t = [get_int() for _ in range(N)]

    t.sort()
    ans = 1
    cnt = 1
    end = t[0] + K

    for i in range(1, N):
        if cnt < C and t[i] <= end:
            cnt += 1
        else:
            cnt = 1
            end = t[i] + K
            ans += 1

    out(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
