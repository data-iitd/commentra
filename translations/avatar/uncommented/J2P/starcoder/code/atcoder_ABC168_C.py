import math
import sys

def main():
    A = int(sys.stdin.readline())
    B = int(sys.stdin.readline())
    H = int(sys.stdin.readline())
    M = int(sys.stdin.readline())
    AA = A * A
    BB = B * B
    HH = H * 30 + M / 2
    kaku = (60 * HH - M) * math.pi / 180
    ans2 = AA + BB - 2 * math.sqrt(AA * BB * math.cos(kaku))
    print(ans2)

if __name__ == '__main__':
    main()

