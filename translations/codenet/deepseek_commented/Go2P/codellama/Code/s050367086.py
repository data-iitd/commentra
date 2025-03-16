
import sys

def get_scanner(fp):
    scanner = fp.split()
    return scanner

def get_next_string(scanner):
    return scanner.pop(0)

def get_next_int(scanner):
    return int(get_next_string(scanner))

def get_next_int64(scanner):
    return int(get_next_string(scanner))

def get_next_uint64(scanner):
    return int(get_next_string(scanner))

def get_next_float64(scanner):
    return float(get_next_string(scanner))

def main():
    fp = sys.stdin
    wfp = sys.stdout

    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    scanner = get_scanner(fp)
    writer = wfp.write

    s = get_next_string(scanner)
    t = get_next_string(scanner)

    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt-1)//ns+1)

    sss = "".join(ss) + "".join(ss)

    ok = [False] * ns

    uni = list(range(ns))
    mp = MP()
    mp.init(t)
    m = 0
    for i in range(ns):
        uni[i] = i
    o = False
    for i in range(ns):
        o = True
        for m in range(nt):
            if t[m] != sss[i+m]:
                o = False
                break
            m += 1
        ok[i] = o
        if o:
            i += nt - mp.table[m]
            m = mp.table[m]
        for m in range(0, -1):
            if t[m] != sss[i+m]:
                i += m - mp.table[m]
                m = mp.table[m]
        i -= 1
        m += 1

    ans = 0
    r, rr = 0, 0
    for i in range(ns):
        if ok[i] == False:
            continue
        if ok[(i+nt)%ns] == False:
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
        if ok[r] == False:
            continue
        counter[r] += 1
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]

    print(ans)

    writer.flush()

class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    def init(self, s):
        self.s = s
        n = len(s)
        table = [-1] * (n+1)
        j = -1
        for i in range(n):
            for j in range(j, -1):
                if s[i] != s[j]:
                    j = table[j]
            j += 1
            table[i+1] = j
        self.table = table

def root(i, uni):
    if i == uni[i]:
        return i

    uni[i] = root(uni[i], uni)
    return uni[i]

