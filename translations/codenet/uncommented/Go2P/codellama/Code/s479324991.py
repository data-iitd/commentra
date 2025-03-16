
import sys

def main():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    arr.sort()
    prev = arr[0]
    for i in range(1, len(arr)):
        prev = (prev + arr[i]) / 2

    print(prev)

if __name__ == "__main__":
    main()

