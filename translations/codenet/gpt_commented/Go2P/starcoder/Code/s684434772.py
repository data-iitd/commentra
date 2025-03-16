def main():
    # Initialize a new scanner for reading input
    sc = NewScanner()

    # Read two integers n and k from input
    n = sc.ReadInt()
    k = sc.ReadInt()

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
    min = (k-1) * k / 2
    max = (2*n-k+1) * k / 2
    # Return the count of combinations
    return int(max - min + 1)

# util
# *   math/simple

# Abs returns the absolute value of an integer
def Abs(x):
    if x >= 0:
        return x
    return -x

# Min returns the minimum value from a list of integers
def Min(values):
    if len(values) == 0:
        panic("no values")
    min = values[0]
    for v in values:
        if v < min:
            min = v
    return min

# Max returns the maximum value from a list of integers
def Max(values):
    if len(values) == 0:
        panic("no values")
    max = values[0]
    for v in values:
        if v > max:
            max = v
    return max

# Pow calculates the power of a base raised to an exponent
def Pow(base, exponent):
    answer = 1
    for i in range(0, exponent):
        answer *= base
    return answer

# Abs64 returns the absolute value of an int64
def Abs64(x):
    if x >= 0:
        return x
    return -x

# Min64 returns the minimum value from a list of int64 values
def Min64(values):
    if len(values) == 0:
        panic("no values")
    min = values[0]
    for v in values:
        if v < min:
            min = v
    return min

# Max64 returns the maximum value from a list of int64 values
def Max64(values):
    if len(values) == 0:
        panic("no values")
    max = values[0]
    for v in values:
        if v > max:
            max = v
    return max

# Pow64 calculates the power of a base (int64) raised to an exponent
def Pow64(base, exponent):
    answer = 1
    for i in range(0, exponent):
        answer *= base
    return answer

# *   io

# Scanner is a custom input scanner that reads words from standard input
class Scanner:
    def __init__(self):
        self.bufScanner = bufio.Scanner(sys.stdin)
        self.bufScanner.split(bufio.ScanWords) # Split input by words

    def ReadString(self):
        bufSc = self.bufScanner
        bufSc.scan() # Scan the next word
        return bufSc.text() # Return the scanned text

    def ReadInt(self):
        bufSc = self.bufScanner
        bufSc.scan() # Scan the next word
        text = bufSc.text()

        # Convert the scanned text to an integer
        num, err = int(text), None
        if err!= None:
            panic(err) # Panic if conversion fails
        return num

    def ReadInt64(self):
        bufSc = self.bufScanner
        bufSc.scan() # Scan the next word
        text = bufSc.text()

        # Convert the scanned text to an int64
        num, err = int(text), None
        if err!= None:
            panic(err) # Panic if conversion fails
        return num

