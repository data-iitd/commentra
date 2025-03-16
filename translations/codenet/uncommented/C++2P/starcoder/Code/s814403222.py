
import sys
import math

def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        v = []
        for i in range(n):
            v.append([0, ''])
        for i in range(n):
            line = sys.stdin.readline().split()
            v[i][1] = line[0]
            m = int(line[1])
            for j in range(m):
                a = int(sys.stdin.readline())
                v[i][0] += n - len(d[a])
                for k in d[a]:
                    v[k][0] -= 1
                d[a].append(i)
        v.sort()
        print(v[0][0], v[0][1])

if __name__ == '__main__':
    d = [[] for i in range(33)]
    main()

