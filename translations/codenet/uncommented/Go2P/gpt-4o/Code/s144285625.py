import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    n = next_int()
    ar = [next_int() for _ in range(3 * n)]
    ar.sort()
    total_sum = 0
    for i in range(n):
        total_sum += ar[3 * n - (i + 1) * 2]
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
