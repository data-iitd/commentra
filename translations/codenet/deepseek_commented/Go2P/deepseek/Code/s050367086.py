import sys
import os
import io
import re

class MP:
    def __init__(self, s):
        self.s = s
        self.table = self.build_table(s)

    def build_table(self, s):
        n = len(s)
        table = [0] * (n + 1)
        table[0] = -1
        j = -1
        for i in range(n):
            while j >= 0 and s[i] != s[j]:
                j = table[j]
            j += 1
            table[i + 1] = j
        return table

def get_next_string(scanner):
    return scanner.readline().strip()

def get_next_int(scanner):
    return int(get_next_string(scanner))

def get_next_int64(scanner):
    return int(get_next_string(scanner))

def get_next_uint64(scanner):
    return int(get_next_string(scanner))

def get_next_float64(scanner):
    return float(get_next_string(scanner))

def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

def main():
    fp = sys.stdin
    wfp = sys.stdout

    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"), "r")
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    scanner = io.TextIOWrapper(fp)
    writer = io.TextIOWrapper(wfp)

    s = get_next_string(scanner)
    t = get_next_string(scanner)

    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt - 1) // ns + 1)

    sss = ''.join(ss) * 2

    ok = [False] * ns

    uni = [i for i in range(ns)]
    mp = MP(t)
    m = 0
    for i in range(ns):
        o = True
        for m in range(nt):
            if t[m] != sss[i + m]:
                o = False
                break
        ok[i] = o
        if o:
            i += nt - mp.table[m]
            m = mp.table[m]
        while m >= 0 and t[m] != sss[i + m]:
            i += m - mp.table[m]
            m = mp.table[m]
        i -= 1
        m += 1

    ans = 0
    for i in range(ns):
        if not ok[i]:
            continue
        if ok[(i + nt) % ns]:
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
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]

    print(ans)

    writer.flush()

if __name__ == "__main__":
    main()
