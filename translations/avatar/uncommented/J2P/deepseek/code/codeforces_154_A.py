import sys

def main():
    input_line = sys.stdin.readline().strip()
    arr = list(input_line)
    N = len(arr)
    set_ = set()
    K = int(sys.stdin.readline().strip())
    res = 0

    for _ in range(K):
        input_line = sys.stdin.readline().strip()
        a = 0
        b = 0
        for i in range(N):
            if arr[i] == input_line[0]:
                a += 1
            elif arr[i] == input_line[1]:
                b += 1
            else:
                res += min(a, b)
                a = b = 0
        res += min(a, b)

    print(res)

if __name__ == "__main__":
    main()
