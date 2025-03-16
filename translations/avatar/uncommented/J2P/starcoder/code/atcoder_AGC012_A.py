
import sys

def main():
    n = int(sys.stdin.readline())
    array = [int(sys.stdin.readline()) for _ in range(3*n)]
    array.sort()
    head = len(array) - 2
    res = 0
    for i in range(n):
        res += array[head]
        head -= 2
    print(res)

if __name__ == "__main__":
    main()

