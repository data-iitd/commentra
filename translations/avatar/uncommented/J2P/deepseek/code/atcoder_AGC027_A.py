import sys

def main():
    N = int(input().strip())
    x = int(input().strip())
    sweet = list(map(int, input().strip().split()))
    sweet.sort()
    num = 0
    for i in range(N):
        if x - sweet[num] >= 0:
            x = x - sweet[num]
            num += 1
        else:
            break
    if num == N and x > 0:
        num -= 1
    print(num)

if __name__ == "__main__":
    main()
