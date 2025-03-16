
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

def getNextUint64(scanner):
    return int(getNextString(scanner))

def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    fp = sys.stdin
    wfp = sys.stdout

    if len(sys.argv) > 1:
        fp = open(sys.argv[1])
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    scanner = getScanner(fp)
    writer = wfp

    n = getNextInt(scanner)
    ll = [0] * n

    for i in range(n):
        ll[i] = getNextInt(scanner)

    ll.sort()

    ans = 0
    for i in range(n-2):
        for j in range(i+1, n-1):
            l = j + 1
            r = n
            while l < r:
                m = (l + r) >> 1
                if ll[m] < ll[i] + ll[j]:
                    l = m + 1
                    continue
                r = m

            ans += l - (j + 1)

    print(ans, file=writer)

    writer.flush()

