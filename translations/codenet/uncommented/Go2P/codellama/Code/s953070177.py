
import sys

def getScanner(fp):
    scanner = fp.split()
    return scanner

def getNextString(scanner):
    return scanner.pop(0)

def getNextInt(scanner):
    return int(getNextString(scanner))

def getNextInt64(scanner):
    return int(getNextString(scanner))

def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')

    scanner = getScanner(fp)

    writer = sys.stdout

    n = getNextInt(scanner)

    aa = [0] * (n+2)
    sum = 0
    for i in range(0, n):
        aa[i+1] = getNextInt(scanner)
        sum += abs(aa[i+1] - aa[i])

    sum += abs(aa[n+1] - aa[n])

    for i in range(1, n+1):
        ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1])
        print(ans)

    # 