
import sys

def getScanner(fp):
    return bufio.Scanner(fp)

def getNextString(scanner):
    scanner.scan()
    return scanner.string()

def getNextInt(scanner):
    return int(getNextString(scanner))

def getNextInt64(scanner):
    return int(getNextString(scanner))

def getNextUint64(scanner):
    return int(getNextString(scanner))

def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    cnt = 0
    fp = sys.stdin
    wfp = sys.stdout

    if os.getenv("MASPY") == "ますπ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
        cnt = 2

    if os.getenv("MASPYPY") == "ますπッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    scanner = getScanner(fp)
    writer = bufio.Writer(wfp)

    solve(scanner, writer)

    for i in range(cnt):
        print("-----------------------------------", file=writer)
        solve(scanner, writer)

    writer.flush()

def solve(scanner, writer):
    k = getNextInt(scanner)
    x = getNextInt(scanner)

    ans = "No"
    if k * 500 >= x:
        ans = "Yes"

    print(ans, file=writer)

