
import sys

def main():
    m = {}
    N, M = map(int, sys.stdin.readline().split())
    for i in range(N):
        x = int(sys.stdin.readline())
        m[x] = m.get(x, 0) + 1
    for i in range(M):
        B, C = map(int, sys.stdin.readline().split())
        m[C] = m.get(C, 0) + B
    ints = sorted(m.keys(), reverse=True)
    rest = N
    sum = 0
    for i in ints:
        num = m[i]
        if num >= rest:
            sum += rest * i
            break
        sum += num * i
        rest -= num
    print(sum)

if __name__ == '__main__':
    main()

