
import sys

def main():
    R, G, B, N = map(int, input().split())
    ans = 0

    for x in range(N + 1):
        for y in range(N + 1):
            tmp = N - R * x - G * y
            if tmp >= 0 and tmp % B == 0:
                ans += 1

    print(ans)

if __name__ == '__main__':
    main()

