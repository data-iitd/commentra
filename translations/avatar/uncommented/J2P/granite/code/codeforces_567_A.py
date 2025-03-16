
import sys

def main():
    a = int(input())
    ar = list(map(int, input().split()))
    max = 0
    min = 0
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

