
import sys

def main():
    K = int(input())

    if K % 2 == 0 or K % 5 == 0:
        print(-1)
        sys.exit()

    if K % 7 == 0:
        K //= 7

    K *= 9

    ans = 1
    remainder = 10 % K

    while remainder!= 1:
        ans += 1
        remainder = (remainder * 10) % K

    print(ans)

if __name__ == '__main__':
    main()

