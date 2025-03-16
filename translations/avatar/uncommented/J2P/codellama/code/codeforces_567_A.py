
import math

def main():
    a = int(input())
    ar = [0] * a
    max = 0
    min = 0
    for i in range(a):
        ar[i] = int(input())
    for i in range(a):
        max = max(ar[i] - ar[0], ar[a - 1] - ar[i])
        if i == 0:
            min = ar[i + 1] - ar[i]
        elif i == a - 1:
            min = ar[i] - ar[i - 1]
        else:
            min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])
        print(min, max)


if __name__ == "__main__":
    main()


