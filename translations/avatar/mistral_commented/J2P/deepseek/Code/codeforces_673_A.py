import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    result, pos, flag = 0, 0, 0

    if a[0] > 15:
        result = 15
    else:
        for i in range(1, n):
            if a[i] - a[i - 1] > 15:
                pos = i - 1
                flag = 1
                break
        if flag == 1:
            result = a[pos] + 15
        else:
            result = a[-1] + 15

    if result > 90:
        result = 90

    print(result)

if __name__ == "__main__":
    main()

