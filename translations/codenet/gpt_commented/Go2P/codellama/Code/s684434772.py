
# Initialize a new scanner for reading input
sc = Scanner()

# Read two integers n and k from input
n = sc.read_int()
k = sc.read_int()

# Initialize a variable to hold the total count
total = 0

# Calculate the total combinations from k to n+1
for i in range(k, n+1):
    total += combi(n, i) # Add combinations for the current i
    total = total % (10**9 + 7) # Apply modulo to prevent overflow

# Print the final total
print(total)

# combi calculates the number of combinations based on the given n and k
def combi(n, k):
    # Calculate the minimum and maximum possible values for combinations
    min = (k-1) * k // 2
    max = (2*n-k+1) * k // 2
    # Return the count of combinations
    return max - min + 1

# util
# *   math/simple

# Abs returns the absolute value of an integer
def abs(x):
    if x >= 0:
        return x
    return -x

# Min returns the minimum value from a list of integers
def min(values):
    if len(values) == 0:
        raise Exception("no values")
    min = values[0]
    for v in values:
        if v < min:
            min = v
    return min

# Max returns the maximum value from a list of integers
def max(values):
    if len(values) == 0:
        raise Exception("no values")
    max = values[0]
    for v in values:
        if v > max:
            max = v
    return max

# Pow calculates the power of a base raised to an exponent
def pow(base, exponent):
    answer = 1
    for i in range(exponent):
        answer *= base
    return answer

# Abs64 returns the absolute value of an int64
def abs64(x):
    if x >= 0:
        return x
    return -x

# Min64 returns the minimum value from a list of int64 values
def min64(values):
    if len(values) == 0:
        raise Exception("no values")
    min = values[0]
    for v in values:
        if v < min:
            min = v
    return min

# Max64 returns the maximum value from a list of int64 values
def max64(values):
    if len(values) == 0:
        raise Exception("no values")
    max = values[0]
    for v in values:
        if v > max:
            max = v
    return max

# Pow64 calculates the power of a base (int64) raised to an exponent
def pow64(base, exponent):
    answer = 1
    for i in range(exponent):
        answer *= base
    return answer

# *   io

# Scanner is a custom input scanner that reads words from standard input
class Scanner:
    # Initialize a new scanner for reading input
    def __init__(self):
        self.bufScanner = bufio.Scanner(sys.stdin)
        self.bufScanner.split(bufio.ScanWords) # Split input by words

    # ReadString reads a single string from input
    def read_string(self):
        bufSc = self.bufScanner
        bufSc.scan() # Scan the next word
        return bufSc.text() # Return the scanned text

    # ReadInt reads a single integer from input
    def read_int(self):
        bufSc = self.bufScanner
        bufSc.scan() # Scan the next word
        text = bufSc.text()

        # Convert the scanned text to an integer
        num = int(text)
        return num

    # ReadInt64 reads a single int64 from input
    def read_int64(self):
        bufSc = self.bufScanner
        bufSc.scan() # Scan the next word
        text = bufSc.text()

        # Convert the scanned text to an int64
        num = int(text)
        return num

