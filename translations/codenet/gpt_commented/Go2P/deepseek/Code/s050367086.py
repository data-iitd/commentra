import sys
import os
import io

# get_input initializes a new scanner for reading from the provided file pointer.
def get_input(fp):
    scanner = io.TextIOWrapper(fp, line_buffering=True)
    scanner.readline()  # Read the next token
    return scanner

# get_next_string retrieves the next string from the scanner.
def get_next_string(scanner):
    return scanner.readline().strip()

# get_next_int retrieves the next integer from the scanner.
def get_next_int(scanner):
    return int(get_next_string(scanner))

# get_next_int64 retrieves the next int64 from the scanner.
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# get_next_uint64 retrieves the next uint64 from the scanner.
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# get_next_float64 retrieves the next float64 from the scanner.
def get_next_float64(scanner):
    return float(get_next_string(scanner))

def main():
    # Initialize file pointers for input and output
    fp = sys.stdin
    wfp = sys.stdout

    # Check for environment variables to override input and output file pointers
    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"), "r")
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    # Create a scanner for reading input and a writer for output
    scanner = get_input(fp)
    writer = io.TextIOWrapper(wfp, line_buffering=True)

    # Read two strings from input
    s = get_next_string(scanner)
    t = get_next_string(scanner)

    # Calculate lengths of the input strings
    ns = len(s)
    nt = len(t)

    # Create a list to hold repeated instances of string s
    ss = [s] * ((nt - 1) // ns + 1)

    # Concatenate the repeated strings to form a new string
    sss = "".join(ss) + "".join(ss)

    # Initialize a list to track matches
    ok = [False] * ns

    # Initialize a unique index array and a pattern matching structure
    uni = [i for i in range(ns)]
    mp = MP()
    mp.init(t)
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

    # Calculate the answer based on the matches found
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

    # Count the number of matches for each unique root
    counter = [0] * ns
    for i in range(ns):
        r = root(i, uni)
        if ok[r]:
            counter[r] += 1
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]

    # Output the final answer
    print(ans)

    writer.flush()

# root function finds the root of the given index using path compression.
def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

# MP class holds the string and its pattern matching table.
class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    # init initializes the pattern matching table for the string.
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

