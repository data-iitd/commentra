
import os
import sys
import math

# Define a function to get the next string from the scanner
def getNextString(scanner):
    return scanner.next()

# Define a function to get the next integer from the scanner
def getNextInt(scanner):
    return int(getNextString(scanner))

# Define a function to get the next int64 from the scanner
def getNextInt64(scanner):
    return int(getNextString(scanner))

# Define a function to get the next uint64 from the scanner
def getNextUint64(scanner):
    return int(getNextString(scanner))

# Define a function to get the next float64 from the scanner
def getNextFloat64(scanner):
    return float(getNextString(scanner))

# Define a function to get the scanner for reading from the provided file pointer
def getScanner(fp):
    return bufio.Scanner(fp)

# Define a function to calculate the root of the given index using path compression
def root(i, uni):
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

# Define a class to hold the string and its pattern matching table
class MP:
    def __init__(self, s):
        self.s = s
        n = len(s)
        self.table = [-1] * (n + 1)
        j = -1
        for i in range(n):
            while j >= 0 and s[i]!= s[j]:
                j = self.table[j]
            j += 1
            self.table[i + 1] = j

# Main function to execute the program
def main():
    # Initialize file pointers for input and output
    fp = sys.stdin
    wfp = sys.stdout

    # Check for environment variables to override input and output file pointers
    if os.environ.get("MASPY") == "ますπ":
        fp = open(os.environ.get("BEET_THE_HARMONY_OF_PERFECT"))
    if os.environ.get("MASPYPY") == "ますπッピ":
        wfp = open(os.environ.get("NGTKANA_IS_GENIUS10"), "w")

    # Create a scanner for reading input and a writer for output
    scanner = getScanner(fp)
    writer = bufio.BufferedWriter(wfp)

    # Read two strings from input
    s = getNextString(scanner)
    t = getNextString(scanner)

    # Calculate lengths of the input strings
    ns = len(s)
    nt = len(t)

    # Create a slice to hold repeated instances of string s
    ss = [s] * ((nt - 1) // ns + 1)
    sss = ''.join(ss)

    # Initialize a boolean slice to track matches
    ok = [False] * ns

    # Initialize a unique index array and a pattern matching structure
    uni = list(range(ns))
    mp = MP(t)
    m = 0
    for i in range(ns):
        uni[i] = i  # Set each index to itself initially
    o = True

    # Check for matches of string t in the concatenated string sss
    for i in range(ns):
        o = True
        for m in range(nt):
            if t[m]!= sss[i + m]:  # Compare characters
                o = False
                break
        ok[i] = o  # Store the result of the match
        if o:
            i += nt - mp.table[m]  # Update index based on the pattern table
            m = mp.table[m]  # Update match index
        while m >= 0 and t[m]!= sss[i + m]:
            i += m - mp.table[m]  # Update index if mismatch occurs
            m = mp.table[m]  # Update match index
        i -= 1  # Adjust index for the next iteration
        m += 1  # Move to the next character

    # Calculate the answer based on the matches found
    ans = 0
    r = 0
    rr = 0
    for i in range(ns):
        if not ok[i]:
            continue  # Skip if no match
        if not ok[(i + nt) % ns]:
            continue  # Skip if no match for the next index
        r = root(i, uni)  # Find the root of the current index
        rr = root((i + nt) % ns, uni)  # Find the root of the next index
        if rr == r:
            writer.write('-1\n')  # Output -1 if they are in the same component
            return
        uni[rr] = r  # Union the two components

    # Count the number of matches for each unique root
    counter = [0] * ns
    for i in range(ns):
        r = root(i, uni)  # Find the root for the current index
        if not ok[r]:
            continue  # Skip if no match
        counter[r] += 1  # Increment the count for the root
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]  # Update the answer with the maximum count

    # Output the final answer
    writer.write(str(ans) + '\n')

    writer.flush()  # Flush the writer to ensure all output is written

# Call the main function to execute the program
if __name__ == "__main__":
    main()

