import sys

def main():
    n, k = map(int, sys.stdin.readline().split())
    arr = list(map(int, sys.stdin.readline().split()))
    res = []
    o = 0
    e = 0
    
    for i in range(n):
        if arr[i] == 1:
            o += 1
        else:
            e += 1
    
    for _ in range(k):
        l, r = map(int, sys.stdin.readline().split())
        if (r - l + 1) % 2 == 1:
            res.append("0\n")
        else:
            if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
                res.append("1\n")
            else:
                res.append("0\n")
    
    sys.stdout.write(''.join(res))

if __name__ == "__main__":
    main()
