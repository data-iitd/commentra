
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
        fp = open(sys.argv[1], 'r')
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    scanner = getScanner(fp)
    writer = wfp

    n = getNextInt(scanner)

    ans = "second"
    for i in range(n):
        a = getNextInt(scanner)
        if a%2 == 1:
            ans = "first"
            break

    print(ans, file=writer)

if __name__ == "__main__":
    main()

