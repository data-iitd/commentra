
# Package main is the entry point of the program
import sys

# getScanner returns a new bufio.Scanner from the given file pointer
def getScanner(fp):
    scanner = fp.split()
    return scanner

# getNextString reads and returns the next string from the scanner
def getNextString(scanner):
    return scanner.next()

# getNextInt reads and converts the next integer from the scanner
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 reads and converts the next int64 from the scanner
def getNextInt64(scanner):
    return int(getNextString(scanner))

# getNextUint64 reads and converts the next uint64 from the scanner
def getNextUint64(scanner):
    return int(getNextString(scanner))

# getNextFloat64 reads and converts the next float64 from the scanner
def getNextFloat64(scanner):
    return float(getNextString(scanner))

# main function is the entry point of the program
def main():
    # Open the standard input and output files
    fp = sys.stdin
    wfp = sys.stdout

    # If environment variables are set, open input and output files accordingly
    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    # Initialize scanner and writer
    scanner = getScanner(fp)
    writer = wfp

    # Read the first two strings from the input
    s = getNextString(scanner)
    t = getNextString(scanner)

    # Initialize variables and structures
    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt-1)/ns+1)

    # Initialize ss with repeated string s
    for i in range(len(ss)):
        ss[i] = s

    # Combine all ss strings into one long string
    sss = "".join(ss) + "".join(ss)

    # Initialize boolean array ok to keep track of unique characters
    ok = [False] * ns

    # Initialize unordered map mp and array uni for suffix array calculation
    mp = {}
    mp.init(t)
    m = 0

    # Initialize uni array with indices from 0 to n-1
    uni = [i for i in range(ns)]

    # Initialize variable o for checking if current and next characters match
    o = True

    # Iterate through all characters in string s
    for i in range(ns):
        # Initialize o to true
        o = True

        # Iterate through all characters in string t
        for m in range(nt):
            # Check if current character in s matches the character at the same position in t
            if t[m] != sss[i+m]:
                # If not, set o to false and break the loop
                o = False
                break
            # Increment m
            m += 1

        # If all characters match, set ok[i] to true and update variables r and m accordingly
        if o:
            i += nt - mp.table[m]
            m = mp.table[m]

        # While characters in s and t do not match, update i and m accordingly
        while m >= 0 and t[m] != sss[i+m]:
            i += m - mp.table[m]
            m = mp.table[m]

        # Decrement i and increment m to move to the next pair of characters
        i -= 1
        m += 1

    # Initialize variable ans to store the answer
    ans = 0

    # Initialize variables r and rr for root calculation
    r = 0
    rr = 0

    # Iterate through all characters in string s again
    for i in range(ns):
        # If ok[i] is false, continue to the next iteration
        if ok[i] == False:
            continue

        # If ok[(i+nt)%ns] is false, continue to the next iteration
        if ok[(i+nt)%ns] == False:
            continue

        # Calculate roots r and rr of indices i and (i+nt)%ns respectively
        r = root(i, uni)
        rr = root((i+nt)%ns, uni)

        # If roots r and rr are equal, print -1 and exit the program
        if rr == r:
            print(-1)
            return

        # Update uni array with root r
        uni[rr] = r

    # Initialize counter array to store the frequency of each root
    counter = [0] * ns

    # Iterate through all roots and update their frequencies in counter array
    for i in range(ns):
        r = root(i, uni)
        if ok[r] == False:
            continue
        counter[r] += 1

    # Find the maximum frequency in counter array and store it in variable ans
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]

    # Print the answer
    print(ans)

    # Flush the writer buffer
    writer.flush()

# root function returns the root of the given index in uni array
def root(i, uni):
    # If index i is equal to its root, return i
    if i == uni[i]:
        return i

    # Recursively call root function with the root of index i
    uni[i] = root(uni[i], uni)
    return uni[i]

# MP type represents a suffix array data structure
class MP:
    def __init__(self, s):
        self.s = s
        n = len(s)
        table = [0] * (n+1)
        table[0] = -1 # Set first index to -1 for initialization
        j = -1
        for i in range(n):
            # While j is not equal to the root of the previous character, update j
            while j >= 0 and s[i] != s[j]:
                j = table[j]
            j += 1
            # Set table[i] to the index of the next occurrence of the current character in s
            table[i+1] = j
        self.table = table

    # init initializes the MP structure with the given string s
    def init(self, s):
        self.s = s
        n = len(s)
        table = [0] * (n+1)
        table[0] = -1 # Set first index to -1 for initialization
        j = -1
        for i in range(n):
            # While j is not equal to the root of the previous character, update j
            while j >= 0 and s[i] != s[j]:
                j = table[j]
            j += 1
            # Set table[i] to the index of the next occurrence of the current character in s
            table[i+1] = j
        self.table = table

