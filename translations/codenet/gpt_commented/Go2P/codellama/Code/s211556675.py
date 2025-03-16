
# I/O
# Scanner struct to facilitate reading input from standard input
class Scanner:
    def __init__(self):
        self.sc = bufio.Scanner(sys.stdin)
        self.sc.split(bufio.ScanWords) # Split input by words
        self.sc.buffer(1024, int(1e+9)) # Set buffer size

    # nextStr reads the next string from input
    def nextStr(self):
        self.sc.scan()
        return self.sc.text()

    # nextInt reads the next integer from input
    def nextInt(self):
        i, e = strconv.Atoi(self.nextStr()) # Convert string to integer
        if e != None:
            panic(e) # Panic if conversion fails
        return i

    # nextFloat reads the next float from input
    def nextFloat(self):
        f, e = strconv.ParseFloat(self.nextStr(), 64) # Convert string to float
        if e != None:
            panic(e) # Panic if conversion fails
        return f

    # nextRuneSlice reads the next string and converts it to a slice of runes
    def nextRuneSlice(self):
        return list(self.nextStr())

    # nextIntSlice reads n integers from input and returns them as a slice
    def nextIntSlice(self, n):
        res = [] # Create a slice to hold the integers
        for i in range(n):
            res.append(self.nextInt()) # Read each integer
        return res

    # nextFloatSlice reads n floats from input and returns them as a slice
    def nextFloatSlice(self, n):
        res = [] # Create a slice to hold the floats
        for i in range(n):
            res.append(self.nextFloat()) # Read each float
        return res

# Arithmetic functions

# max returns the maximum value from a list of integers
def max(nums):
    m = nums[0] # Initialize max with the first element
    for i in nums:
        if m < i:
            m = i # Update max if a larger value is found
    return m

# min returns the minimum value from a list of integers
def min(nums):
    m = nums[0] # Initialize min with the first element
    for i in nums:
        if m > i:
            m = i # Update min if a smaller value is found
    return m

# abs returns the absolute value of an integer
def abs(x):
    if x > 0:
        return x # Return x if positive
    return -x # Return -x if negative

# pow computes x raised to the power of y
def pow(x, y):
    res = 1 # Initialize result
    for i in range(y):
        res *= x # Multiply res by x, y times
    return res

# Sort related types and methods

# Val struct to hold a value and its associated ID
class Val:
    def __init__(self, id, num):
        self.id = id
        self.num = num

# ByNum is a type that implements sort.Interface based on the num field
class ByNum(list):
    def __init__(self, vals):
        super().__init__(vals)

    # Len returns the number of elements in the collection
    def Len(self):
        return len(self)

    # Less reports whether the element with index i should sort before the element with index j
    def Less(self, i, j):
        return self[i].num < self[j].num

    # Swap exchanges the elements with indexes i and j
    def Swap(self, i, j):
        self[i], self[j] = self[j], self[i]

# Main function
def main():
    sc = Scanner() # Create a new scanner for input
    wtr = bufio.Writer(sys.stdout) # Create a buffered writer for output

    # Read four integers from input
    A, B, C, K = sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()

    # Determine the maximum value among A, B, and C
    ma = max([A, B, C])
    rest = 0 # Initialize the rest variable to hold the sum of the other two values

    # Calculate the sum of the two smaller values
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    # Double the maximum value K times
    for i in range(1, K+1):
        ma *= 2

    # Output the final result: doubled max value plus the sum of the other two
    print(ma+rest, file=wtr)
    wtr.flush() # Ensure all buffered data is written to output

