import sys

def main():
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    a = [0] + a  # To make the array 1-indexed

    pre = [0] * (n + 1)
    last = [0] * (n + 1)

    sumpre = 0
    sumlast = 0

    for i in range(1, n):
        sumpre += a[i]
        pre[i] = sumpre

    for i in range(n, 1, -1):
        sumlast += a[i]
        last[i] = sumlast

    d = (1 << 60)
    for i in range(1, n):
        d = min(d, abs(pre[i] - last[i + 1]))

    print(d)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
