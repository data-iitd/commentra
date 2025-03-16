import sys

def main():
    n = int(sys.stdin.readline())
    aPrev = 0
    ans = 0
    for i in range(n):
        a = int(sys.stdin.readline())
        if a > i or a > aPrev+1:
            print(-1)
            return
        if a == aPrev+1:
            ans += 1
        else:
            ans += a
        aPrev = a
    print(ans)

if __name__ == '__main__':
    main()

