
import sys

def getNextWord(scanner):
    scanner.next()
    return scanner.next()

def getNextInt(scanner):
    return int(getNextWord(scanner))

def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    scanner = bufio.Scanner(fp)
    scanner.split(bufio.ScanWords)
    writer = bufio.Writer(sys.stdout)

    n = getNextInt(scanner)
    m = getNextInt(scanner)
    aa = {}
    for i in range(m):
        aa[getNextInt(scanner)] = 1

    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(n):
        for ii in range(1, 3):
            if i + ii > n:
                break
            if i + ii in aa:
                continue
            dp[i + ii] += dp[i]
            dp[i + ii] %= 1000000007
    print(dp[n])

    writer.flush()

