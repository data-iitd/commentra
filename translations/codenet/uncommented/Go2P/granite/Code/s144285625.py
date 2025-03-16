
import sys

def main():
    n = int(input())
    ar = list(map(int, input().split()))
    ar.sort(reverse=True)
    sum = 0
    for i in range(n):
        sum += ar[i*2+1]
    print(sum)

if __name__ == "__main__":
    main()

