
import sys

def getScanner(fp):
    scanner = sys.stdin
    if fp != sys.stdin:
        scanner = fp
    return scanner

def getNextString(scanner):
    return scanner.readline().strip()

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
    cnt = 0

    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
        cnt = 2
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    scanner = getScanner(fp)
    writer = sys.stdout
    solve(scanner, writer)
    for i in range(cnt):
        print("-----------------------------------")
        solve(scanner, writer)

def solve(scanner, writer):
    k = getNextInt(scanner)
    x = getNextInt(scanner)

    ans = "No"
    if k*500 >= x:
        ans = "Yes"
    print(ans, file=writer)

