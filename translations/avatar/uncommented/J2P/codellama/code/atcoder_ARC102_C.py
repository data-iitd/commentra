import sys

def nchoosek(n, k):
    if k < 0 or n < k:
        return 0
    if k == 0 or n == k:
        return 1
    return nchoosek(n - 1, k - 1) + nchoosek(n - 1, k)

def main():
    k = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    for i in range(2, 2 * k + 1):
        pairs = 0
        if i > k:
            pairs = k - i // 2
        else:
            pairs = (i - 1) // 2
        active = k - 2 * pairs
        if i % 2 == 0:
            active -= 1
        times2 = 1
        total = 0
        for j in range(0, pairs + 1):
            choice = times2 * nchoosek(pairs, j) % 998244353
            times2 = times2 * 2 % 998244353
            if active + j - 1 < 0:
                continue
            total += choice * nchoosek(n + active - 1, active + j - 1)
            if i % 2 == 0:
                total += choice * nchoosek(n + active - 2, active + j - 1)
            total %= 998244353
        print(total)

if __name__ == "__main__":
    main()

