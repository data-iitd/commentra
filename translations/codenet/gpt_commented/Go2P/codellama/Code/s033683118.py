
import sys

# getScanner initializes a new scanner for reading from the provided file pointer.
# It sets the scanner to split input by words and allocates a buffer for larger inputs.
def getScanner(fp):
    scanner = sys.stdin
    return scanner

# getNextString retrieves the next string from the scanner.
def getNextString(scanner):
    return scanner.readline().strip()

# getNextInt converts the next string from the scanner to an integer.
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 converts the next string from the scanner to a 64-bit integer.
def getNextInt64(scanner):
    return int(getNextString(scanner))

# getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
def getNextUint64(scanner):
    return int(getNextString(scanner))

# getNextFloat64 converts the next string from the scanner to a float64.
def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    # Initialize file pointers for input and output.
    fp = sys.stdin
    wfp = sys.stdout
    cnt = 0

    # Check for environment variables to determine input and output files.
    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
        cnt = 2 # Set the count for additional processing.
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    # Create a scanner for reading input and a writer for output.
    scanner = getScanner(fp)
    writer = open(wfp, "w")

    # Solve the problem for the first time.
    solve(scanner, writer)

    # If cnt is greater than 0, solve the problem additional times.
    for i in range(cnt):
        writer.write("-----------------------------------\n")
        solve(scanner, writer)

    # Flush the writer to ensure all output is written.
    writer.flush()

# solve processes the input values and determines if the condition is met.
# It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
def solve(scanner, writer):
    k = getNextInt(scanner) # Read the first integer k.
    x = getNextInt(scanner) # Read the second integer x.

    ans = "No" # Default answer is "No".
    if k*500 >= x: # Check the condition.
        ans = "Yes" # Update answer to "Yes" if condition is met.
    writer.write(ans + "\n") # Output the result.

