import sys

mod = 998244353

def main():
    N = int(sys.stdin.readline().strip())
    total_sum = 0
    for i in range(1, N + 1):
        if i % 3 == 0 or i % 5 == 0:
            continue
        total_sum += i
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
