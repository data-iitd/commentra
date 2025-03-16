def main():
    N = int(input())
    nx, ny, nt = 0, 0, 0
    for _ in range(N):
        t, x, y = map(int, input().split())
        tmp = t - nt - (abs(x - nx) + abs(y - ny))
        if tmp < 0 or tmp % 2 != 0:
            print("No")
            return
        nx, ny, nt = x, y, t
    print("Yes")


main()
