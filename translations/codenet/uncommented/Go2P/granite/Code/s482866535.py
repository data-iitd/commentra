
import sys

def getScanner(fp):
    return bufio.Scanner(fp).split()

def getNextString(scanner):
    return next(scanner)

def getNextInt(scanner):
    return int(getNextString(scanner))

def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    scanner = getScanner(fp)
    writer = bufio.Writer(sys.stdout)

    n = getNextInt(scanner)
    mm = [0] * (n + 1)
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n):
        mm[i] = getNextInt(scanner)
        mm[i + 1] = getNextInt(scanner)

    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            for k in range(i, j):
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    print(dp[1][n])

    writer.flush()

