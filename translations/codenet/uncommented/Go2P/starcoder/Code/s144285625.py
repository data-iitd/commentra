
import sys

def main():
    n = int(sys.stdin.readline())
    ar = [int(x) for x in sys.stdin.readline().split()]
    ar.sort()
    sum = 0
    for i in range(n):
        sum += ar[3*n-(i+1)*2]
    print(sum)

if __name__ == "__main__":
    main()

