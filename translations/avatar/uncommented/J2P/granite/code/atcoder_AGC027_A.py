
import sys

def main():
    N, x = map(int, input().split())
    sweet = list(map(int, input().split()))
    sweet.sort()
    num = 0
    for i in range(N):
        if x - sweet[num] >= 0:
            x -= sweet[num]
            num += 1
        else:
            break
    if num == N and x > 0:
        num -= 1
    print(num)

if __name__ == "__main__":
    main()

