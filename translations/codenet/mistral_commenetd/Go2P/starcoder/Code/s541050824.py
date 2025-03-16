# Importing required packages
import sys

# Initializing variables
reader = bufio.NewReader(sys.stdin)
writer = bufio.NewWriter(sys.stdout)

# Reading input
def readLine():
    return reader.readline().strip()

# Writing output
def writeLine(line):
    writer.write(line + "\n")
    writer.flush()

# Main function
def main():
    # Reading input
    n = int(readLine())
    a = list(map(int, readLine().split()))
    b = list(map(int, readLine().split()))

    # Calculating output
    result = 0
    for i in range(n):
        result += a[i] * b[i]

    # Writing output
    writeLine(str(result))

# Entry point
if __name__ == "__main__":
    main()

