import sys

def main():
    n = int(input().strip())
    array = list(map(int, input().strip().split()))
    array.sort()
    head = len(array) - 2
    res = 0
    for i in range(n):
        res += array[head]
        head -= 2
    print(res)

if __name__ == "__main__":
    main()
