
#!/usr/bin/env python3

import sys

# getNextInt reads the next token as a string, converts it to an integer, and returns it.
def getNextInt(scanner):
    return int(scanner.readline())

# getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
def getNextInt64(scanner):
    return int(scanner.readline())

# getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
def getNextUint64(scanner):
    return int(scanner.readline())

# getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
def getNextFloat64(scanner):
    return float(scanner.readline())

# main function handles file input/output based on command-line arguments.
# It reads integers from the specified file or standard input, sorts them,
# and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
def main():
    # Check if file paths are provided as command-line arguments.
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')
    else:
        fp = sys.stdin
        wfp = sys.stdout

    scanner = fp
    writer = wfp

    # Read the number of elements.
    n = getNextInt(scanner)
    ll = []

    # Read n integers into the slice ll.
    for i in range(n):
        ll.append(getNextInt(scanner))

    # Sort the slice ll.
    ll.sort()

    # Initialize the answer variable.
    ans = 0

    # Iterate through possible triplets (i, j, m) where i < j < m.
    for i in range(n-2):
        for j in range(i+1, n-1):
            l = j + 1
            r = n
            while l < r:
                m = (l + r) >> 1
                if ll[m] < ll[i] + ll[j]:
                    l = m + 1
                    continue
                r = m

            # Add the number of valid m's to the answer.
            ans += l - (j + 1)

    # Print the final answer to the standard output.
    print(ans, file=writer)

    # Flush the writer to ensure all data is written to the file or standard output.
    writer.flush()

if __name__ == '__main__':
    main()

