
# <START-OF-CODE>

import sys

def main():
    n = int(sys.stdin.readline())
    ar = [int(sys.stdin.readline()) for i in range(3*n)]
    ar.sort()
    sum = 0
    for i in range(n):
        sum += ar[3*n-(i+1)*2]
    print(sum)

if __name__ == "__main__":
    main()

# 