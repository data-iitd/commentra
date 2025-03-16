
import sys

def getScanner(fp):
    return iter(fp.read().split())

def getNextString(scanner):
    return next(scanner)

def getNextInt(scanner):
    return int(getNextString(scanner))

def getNextInt64(scanner):
    return int(getNextString(scanner))

def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    fp = sys.stdin
    wfp = sys.stdout

    if os.getenv("MASPY") == "ますぴ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
    if os.getenv("MASPYPY") == "ますぴぴ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    scanner = getScanner(fp)
    writer = bufio.Writer(wfp)

    s = getNextString(scanner)
    t = getNextString(scanner)

    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt-1)//ns+1)

    sss = ''.join(ss) * 2

    ok = [False] * ns

    uni = list(range(ns))
    mp = MP()
    mp.init(t)
    m = 0
    for i in range(ns):
        ok[i] = True
        m = 0
        while m < nt:
            if t[m]!= sss[i+m]:
                ok[i] = False
                break
            m += 1
        if ok[i]:
            i += nt - mp.table[m]
            m = mp.table[m]
        while m >= 0 and t[m]!= sss[i+m]:
            i += m - mp.table[m]
            m = mp.table[m]
        i -= 1
        m += 1

    ans = 0
    r = rr = 0
    for i in range(ns):
        if not ok[i]:
            continue
        if not ok[(i+nt)%ns]:
            continue
        r = root(i, uni)
        rr = root((i+nt)%ns, uni)
        if rr == r:
            print(-1)
            return
        uni[rr] = r

    counter = [0] * ns
    for i in range(ns):
        r = root(i, uni)
        if not ok[r]:
            continue
        counter[r] += 1
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]

    print(ans)

    writer.flush()

def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

# MP...
class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    def init(self, s):
        self.s = s
        n = len(s)
        table = [0] * (n+1)
        table[0] = -1
        j = -1
        for i in range(n):
            while j >= 0 and s[i]!= s[j]:
                j = table[j]
            j += 1
            table[i+1] = j
        self.table = table

main()

