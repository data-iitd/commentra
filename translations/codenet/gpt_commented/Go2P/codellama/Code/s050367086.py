
import sys

# getScanner initializes a new scanner for reading from the provided file pointer.
def getScanner(fp):
    scanner = fp.read().split()
    return scanner

# getNextString retrieves the next string from the scanner.
def getNextString(scanner):
    return scanner.pop(0)

# getNextInt retrieves the next integer from the scanner.
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 retrieves the next int64 from the scanner.
def getNextInt64(scanner):
    return int(getNextString(scanner))

# getNextUint64 retrieves the next uint64 from the scanner.
def getNextUint64(scanner):
    return int(getNextString(scanner))

# getNextFloat64 retrieves the next float64 from the scanner.
def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    # Initialize file pointers for input and output
    fp = sys.stdin
    wfp = sys.stdout

    # Check for environment variables to override input and output file pointers
    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT")) # Open specified input file
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w") # Create specified output file

    # Create a scanner for reading input and a writer for output
    scanner = getScanner(fp)
    writer = wfp

    # Read two strings from input
    s = getNextString(scanner)
    t = getNextString(scanner)

    # Calculate lengths of the input strings
    ns = len(s)
    nt = len(t)

    # Create a slice to hold repeated instances of string s
    ss = [s] * ((nt-1)//ns+1)

    # Concatenate the repeated strings to form a new string
    sss = "".join(ss) + "".join(ss)

    # Initialize a boolean slice to track matches
    ok = [False] * ns

    # Initialize a unique index array and a pattern matching structure
    uni = list(range(ns))
    mp = MP()
    mp.init(t) # Initialize the pattern matching table with string t
    m = 0
    for i in range(ns):
        uni[i] = i # Set each index to itself initially
    o = False

    # Check for matches of string t in the concatenated string sss
    for i in range(ns):
        o = True
        for m in range(nt):
            if t[m] != sss[i+m]: # Compare characters
                o = False
                break
        ok[i] = o # Store the result of the match
        if o:
            i += nt - mp.table[m] # Update index based on the pattern table
            m = mp.table[m] # Update match index
        for m in range(nt-1, -1, -1):
            if t[m] != sss[i+m]:
                i += m - mp.table[m] # Update index if mismatch occurs
                m = mp.table[m] # Update match index
        i -= 1 # Adjust index for the next iteration
        m += 1 # Move to the next character

    # Calculate the answer based on the matches found
    ans = 0
    r, rr = 0, 0
    counter = [0] * ns
    for i in range(ns):
        if ok[i] == False:
            continue # Skip if no match
        if ok[(i+nt)%ns] == False:
            continue # Skip if no match for the next index
        r = root(i, uni) # Find the root of the current index
        rr = root((i+nt)%ns, uni) # Find the root of the next index
        if rr == r:
            print(-1) # Output -1 if they are in the same component
            return
        uni[rr] = r # Union the two components
    for i in range(ns):
        if ok[i] == False:
            continue # Skip if no match
        r = root(i, uni) # Find the root for the current index
        counter[r] += 1 # Increment the count for the root
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i] # Update the answer with the maximum count

    # Output the final answer
    print(ans)

    writer.flush() # Flush the writer to ensure all output is written

# root function finds the root of the given index using path compression.
def root(i, uni):
    if i == uni[i]:
        return i # Return if the index is its own root
    uni[i] = root(uni[i], uni) # Path compression
    return uni[i] # Return the root

# MP struct holds the string and its pattern matching table.
class MP:
    def __init__(self):
        self.s = ""
        self.table = []

    # init initializes the pattern matching table for the string.
    def init(self, s):
        self.s = s
        n = len(s)
        table = [-1] * (n+1)
        j = -1
        for i in range(n):
            for j in range(j, -1, -1):
                if s[i] != s[j]:
                    j = table[j] # Update j based on the table
            j += 1
            table[i+1] = j # Fill the table with the length of the longest prefix
        self.table = table # Assign the completed table to the MP struct

