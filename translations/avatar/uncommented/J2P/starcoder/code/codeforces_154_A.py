
# <START-OF-CODE>
import sys

def main():
    infile = sys.stdin
    arr = infile.readline().strip()
    N = len(arr)
    set = set()
    K = int(infile.readline())
    res = 0
    for k in range(K):
        input = infile.readline().strip()
        a = 0
        b = 0
        for i in range(N):
            if arr[i] == input[0]:
                a += 1
            elif arr[i] == input[1]:
                b += 1
            else:
                res += min(a, b)
                a = b = 0
        res += min(a, b)
    print(res)

if __name__ == '__main__':
    main()
# 