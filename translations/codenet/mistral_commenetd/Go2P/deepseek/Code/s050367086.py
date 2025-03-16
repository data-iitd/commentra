import sys
import os
import re

def get_next_string(scanner):
    return scanner.next()

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
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), 'w')

    scanner = get_scanner(fp)
    writer = bufio.Writer(wfp)

    s = get_next_string(scanner)
    t = get_next_string(scanner)

    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt - 1) // ns + 1)

    sss = ''.join(ss) + ''.join(ss)

    ok = [False] * ns

    mp = MP()
    mp.init(t)
    m = 0

    uni = list(range(ns))

    for i in range(ns):
        o = True
        m = 0
        while m < nt:
            if t[m] != sss[i + m]:
                o = False
                break
            m += 1

        if o:
            i += nt - mp.table[m]
            m = mp.table[m]

        while m >= 0 and t[m] != sss[i + m]:
            i -= m - mp.table[m]
            m = mp.table[m]

        i -= 1
        m += 1

    ans = 0

    for i in range(ns):
        if not ok[i]:
            continue
        if not ok[(i + nt) % ns]:
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
        if ok[r]:
            counter[r] += 1

    ans = max(counter)

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
        self.table = [0] * (n + 1)
        self.table[0] = -1
        j = -1
        for i in range(n):
            while j >= 0 and s[i] != s[j]:
                j = self.table[j]
            j += 1
            self.table[i + 1] = j

get_scanner = lambda fp: bufio.Scanner(fp)

if __name__ == "__main__":
    main()
