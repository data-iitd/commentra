import sys

# get_scanner Function
# Purpose: Initializes a scanner for the given file pointer.
# Details: Creates a new scanner and sets it to scan words.
def get_scanner(fp):
    return fp.read().split()

# get_next_string Function
# Purpose: Retrieves the next word from the scanner.
# Details: Scans the next word and returns it.
def get_next_string(scanner):
    return scanner.pop(0)

# get_next_int Function
# Purpose: Retrieves the next word and converts it to an integer.
# Details: Uses `get_next_string` and `int`.
def get_next_int(scanner):
    return int(get_next_string(scanner))

# get_next_int64 Function
# Purpose: Retrieves the next word and converts it to an int64.
# Details: Uses `get_next_string` and `int`.
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# get_next_uint64 Function
# Purpose: Retrieves the next word and converts it to a uint64.
# Details: Uses `get_next_string` and `int`.
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# get_next_float64 Function
# Purpose: Retrieves the next word and converts it to a float64.
# Details: Uses `get_next_string` and `float`.
def get_next_float64(scanner):
    return float(get_next_string(scanner))

# root Function
# Purpose: Implements the union-find structure to find the root of a node.
# Details: Uses path compression to optimize the union-find structure.
def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

# MP Class
# Purpose: Manages the pattern and its pre-processing table for the Boyer-Moore algorithm.
# Details: Initializes the pattern and builds the pre-processing table.
class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    def init(self, s):
        self.s = s
        n = len(s)
        table = [-1] * (n + 1)
        j = -1
        for i in range(n):
            while j >= 0 and s[i] != s[j]:
                j = table[j]
            j += 1
            table[i + 1] = j
        self.table = table

# main Function
# Purpose: Main entry point of the program.
# Details: Sets up input/output streams, reads strings, initializes pattern matching, and performs the main logic.
def main():
    fp = sys.stdin
    wfp = sys.stdout

    if "MASPY" in os.environ and os.environ["MASPY"] == "ますピ":
        fp = open(os.environ["BEET_THE_HARMONY_OF_PERFECT"])
    if "MASPYPY" in os.environ and os.environ["MASPYPY"] == "ますピッピ":
        wfp = open(os.environ["NGTKANA_IS_GENIUS10"], 'w')

    scanner = get_scanner(fp)

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
    r, rr = 0, 0
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
        if not ok[r]:
            continue
        counter[r] += 1
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
