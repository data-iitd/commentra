
import sys

def get_next_word(scanner):
    scanner.scan()
    return scanner.text()

def get_next_int(scanner):
    return int(get_next_word(scanner))

def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    scanner = bufio.Scanner(fp)
    scanner.split(bufio.ScanWords)
    writer = bufio.Writer(sys.stdout)

    n = get_next_int(scanner)
    m = get_next_int(scanner)
    aa = {}
    for i in range(m):
        aa[get_next_int(scanner)] = 1

    dp = [0] * (n+1)
    dp[0] = 1
    for i in range(n):
        for ii in range(1, 3):
            if i+ii > n:
                break
            if aa.get(i+ii):
                continue
            dp[i+ii] += dp[i]
            dp[i+ii] %= 1000000007

    print(dp[n])

    writer.flush()

