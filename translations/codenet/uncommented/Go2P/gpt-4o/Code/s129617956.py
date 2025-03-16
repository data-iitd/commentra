import math
import sys

def next_int():
    return int(sys.stdin.readline().strip())

def min_value(i, j):
    return j if i > j else i

def main():
    n = next_int()
    rt = int(math.sqrt(n))
    minf = 100
    for i in range(1, rt + 1):
        if n % i == 0:
            b = n // i
            ndigit = 0
            while b > 0:
                b //= 10
                ndigit += 1
            minf = min_value(minf, ndigit)
    print(minf)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
