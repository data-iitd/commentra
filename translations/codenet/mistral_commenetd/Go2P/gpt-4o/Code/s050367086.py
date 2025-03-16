# Import necessary modules
import sys

# get_scanner returns a new scanner from the given file pointer
def get_scanner(fp):
    return fp.read().split()

# get_next_string reads and returns the next string from the scanner
def get_next_string(scanner):
    return scanner.pop(0)

# get_next_int reads and converts the next integer from the scanner
def get_next_int(scanner):
    return int(get_next_string(scanner))

# get_next_int64 reads and converts the next int64 from the scanner
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# get_next_uint64 reads and converts the next uint64 from the scanner
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# get_next_float64 reads and converts the next float64 from the scanner
def get_next_float64(scanner):
    return float(get_next_string(scanner))

# root function returns the root of the given index in uni array
def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

# MP class represents a suffix array data structure
class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    # init initializes the MP structure with the given string s
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

# main function is the entry point of the program
def main():
    # Open the standard input and output files
    fp = sys.stdin
    wfp = sys.stdout

    # Read the first two strings from the input
    scanner = get_scanner(fp)
    s = get_next_string(scanner)
    t = get_next_string(scanner)

    # Initialize variables and structures
    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt - 1) // ns + 1)

    # Combine all ss strings into one long string
    sss = ''.join(ss) + ''.join(ss)

    # Initialize boolean array ok to keep track of unique characters
    ok = [False] * ns

    # Initialize MP and calculate suffix array
    mp = MP()
    mp.init(t)
    m = 0

    # Initialize uni array with indices from 0 to n-1
    uni = list(range(ns))

    # Iterate through all characters in string s
    for i in range(ns):
        o = True
        while m < nt:
            if t[m] != sss[i + m]:
                o = False
                break
            m += 1

        if o:
            i += nt - mp.table[m]
            m = mp.table[m]

        while m >= 0 and t[m] != sss[i + m]:
            i += m - mp.table[m]
            m = mp.table[m]

        i -= 1
        m += 1

    # Initialize variable ans to store the answer
    ans = 0

    # Initialize variables r and rr for root calculation
    r = rr = 0

    # Iterate through all characters in string s again
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

    # Initialize counter array to store the frequency of each root
    counter = [0] * ns

    # Iterate through all roots and update their frequencies in counter array
    for i in range(ns):
        r = root(i, uni)
        if not ok[r]:
            continue
        counter[r] += 1

    # Find the maximum frequency in counter array and store it in variable ans
    ans = max(counter)

    # Print the answer
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
