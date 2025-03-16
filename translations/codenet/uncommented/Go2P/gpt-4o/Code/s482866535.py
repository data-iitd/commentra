import sys

def get_next_int(scanner):
    return int(scanner.pop(0))

def main():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            scanner = f.read().split()
    else:
        scanner = sys.stdin.read().split()

    n = get_next_int(scanner)
    mm = [0] * (n + 1)
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(n):
        mm[i] = get_next_int(scanner)
        mm[i + 1] = get_next_int(scanner)

    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            for k in range(i, j):
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    print(dp[1][n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
