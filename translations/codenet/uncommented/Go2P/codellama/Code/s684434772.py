
import sys

def main():
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())

    total = 0
    for i in range(k, n+2):
        total += combi(n, i)
        total = total % (10**9 + 7)
    print(total)

def combi(n, k):
    min = (k-1)*k//2
    max = (2*n-k+1)*k//2
    return max - min + 1

if __name__ == "__main__":
    main()

