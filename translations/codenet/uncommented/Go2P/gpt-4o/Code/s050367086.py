import sys

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
            while j >= 0 and s[i] != s[j]:
                j = table[j]
            j += 1
            table[i + 1] = j
        self.table = table

def get_next_string(scanner):
    return next(scanner)

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
    input_stream = sys.stdin
    output_stream = sys.stdout

    if "MASPY" in os.environ and os.environ["MASPY"] == "ますピ":
        input_stream = open(os.environ["BEET_THE_HARMONY_OF_PERFECT"])
    if "MASPYPY" in os.environ and os.environ["MASPYPY"] == "ますピッピ":
        output_stream = open(os.environ["NGTKANA_IS_GENIUS10"], 'w')

    scanner = iter(input_stream.read().split())
    
    s = get_next_string(scanner)
    t = get_next_string(scanner)

    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt - 1) // ns + 1)

    sss = f"{''.join(ss)}{''.join(ss)}"

    ok = [False] * ns
    uni = list(range(ns))
    mp = MP()
    mp.init(t)
    m = 0

    for i in range(ns):
        o = True
        while m < nt:
            if t[m] != sss[i + m]:
                o = False
                break
            m += 1
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
        if not ok[(i + nt) % ns]:
            continue
        r = root(i, uni)
        rr = root((i + nt) % ns, uni)
        if rr == r:
            print(-1, file=output_stream)
            return
        uni[rr] = r

    counter = [0] * ns
    for i in range(ns):
        r = root(i, uni)
        if not ok[r]:
            continue
        counter[r] += 1
    ans = max(counter)

    print(ans, file=output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
