

import bufio
import os
import sys

def get_scanner(fp):
    scanner = bufio.Scanner(fp)
    scanner.buffer(bytearray(500001), 500000)
    return scanner

def get_next_string(scanner):
    scanner.scan()
    return scanner.text()

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

    if os.environ.get("MASPY") == "ますπ":
        fp = open(os.environ.get("BEET_THE_HARMONY_OF_PERFECT"))
    if os.environ.get("MASPYPY") == "ますπッピ":
        wfp = open(os.environ.get("NGTKANA_IS_GENIUS10"), "w")

    scanner = get_scanner(fp)
    writer = bufio.BufferedWriter(wfp)

    s = get_next_string(scanner)
    t = get_next_string(scanner)

    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt - 1) // ns + 1)
    sss = "".join(ss)

    ok = [False] * ns

    mp = MP()
    mp.init(t)
    m = 0

    uni = list(range(ns))

    o = True

    for i in range(ns):
        o = True
        for m in range(nt):
            if t[m]!= sss[i + m]:
                o = False
                break
        if o:
            i += nt - mp.table[m]
            m = mp.table[m]
        while m >= 0 and t[m]!= sss[i + m]:
            i += m - mp.table[m]
            m = mp.table[m]
        i -= 1
        m += 1

    ans = 0

    r = 0
    rr = 0

    for i in range(ns):
        if ok[i] is False:
            continue
        if ok[(i + nt) % ns] is False:
            continue
        r = root(i, uni)
        rr = root((i + nt) % ns, uni)
        if rr == r:
            print(-1)
            return
        uni[rr] = r

    counter = [0] * ns

    for i in range(ns):
        r = root(i, uni)
        if ok[r] is False:
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

class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    def init(self, s):
        self.s = s
        n = len(s)
        table = [0] * (n + 1)
        table[0] = -1
        j = -1
        for i in range(n):
            while j >= 0 and s[i]!= s[j]:
                j = table[j]
            j += 1
            table[i + 1] = j
        self.table = table

if __name__ == "__main__":
    main()

