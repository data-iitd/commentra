
import sys

def main():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    arr = [int(sys.stdin.readline()) for _ in range(n)]
    o = 0
    e = 0
    for i in range(n):
        if arr[i] == 1:
            o += 1
        else:
            e += 1
    res = ""
    for i in range(k):
        l, r = map(int, sys.stdin.readline().split())
        if (r - l + 1) % 2 == 1:
            res += "0\n"
        else:
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                res += "1\n"
            else:
                res += "0\n"
    print(res)

if __name__ == "__main__":
    main()

