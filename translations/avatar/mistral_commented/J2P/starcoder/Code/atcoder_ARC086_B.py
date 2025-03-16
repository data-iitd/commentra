
import sys

def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    m = 0
    for i in range(1, n):
        if abs(a[m]) > abs(a[i]):
            m = i
    r = []
    if a[m] >= 0:
        for i in range(1, n):
            r.append(str(i) + " " + str(i+1))
    else:
        for i in range(n, 1, -1):
            r.append(str(i) + " " + str(i-1))
    print(len(r))
    for i in r:
        print(i)

if __name__ == "__main__":
    main()

