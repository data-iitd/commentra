
import sys

def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    k = 0
    j = 0
    i = 0
    f = 0
    for k in range(n):
        t = a[k]
        for i in range(n):
            if i!= k:
                for j in range(n-1):
                    if i!= j and t == (a[i] + a[j]):
                        f = 1
                        break
                if f == 1:
                    break
        if f == 1:
            print(k+1, j+1, i+1)
            f = 0
    if f == 0:
        print(-1)

if __name__ == "__main__":
    main()

