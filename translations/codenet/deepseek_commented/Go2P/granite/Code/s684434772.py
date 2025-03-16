
import sys

def main():
    n = int(input())
    k = int(input())

    total = 0
    for i in range(k, n + 2):
        total += combi(n, i)
        total %= (10 ** 9 + 7)
    print(total)

def combi(n, k):
    min_val = (k - 1) * k // 2
    max_val = (2 * n - k + 1) * k // 2
    return max_val - min_val + 1

if __name__ == "__main__":
    main()

