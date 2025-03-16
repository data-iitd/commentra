
import sys

def main():
    m = {}
    N, M = map(int, input().split())
    for i in range(N):
        a = int(input())
        if a in m:
            m[a] += 1
        else:
            m[a] = 1
    for i in range(M):
        B, C = map(int, input().split())
        if C in m:
            m[C] += B
        else:
            m[C] = B
    keys = list(m.keys())
    keys.sort(reverse=True)
    rest = N
    sum = 0
    for i in keys:
        num = m[i]
        if num >= rest:
            sum += rest * i
            break
        sum += num * i
        rest -= num
    print(sum)

if __name__ == "__main__":
    main()

