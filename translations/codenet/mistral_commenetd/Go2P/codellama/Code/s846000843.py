
# The main function is the entry point of the program.
def main():
    # Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
    io = Io()
    io.Flush()

    # Read the number n from the standard input.
    n = io.Int()

    # Initialize an array aa of length n to store the input integers.
    aa = [0] * n

    # Read n integers from the standard input and store them in the aa array using a for loop.
    for i in range(n):
        aa[i] = io.Int()

    # Compute the cumulative sum of the aa array using the CumSum function.
    cumsum = CumSum(aa)

    # Initialize a variable ans to store the answer.
    ans = 2020202020

    # Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
    for i in range(1, len(cumsum)-1):
        # Compute the absolute difference between the last cumulative sum and the current cumulative sum.
        diff1 = abs(cumsum[len(cumsum)-1] - cumsum[i])

        # Compute the difference between the current cumulative sum and the first cumulative sum.
        diff2 = cumsum[i] - cumsum[0]

        # Keep the minimum of these two differences as the answer.
        ans = min(ans, diff1, diff2)

    # Print the answer using the PrintLn method of the Io struct.
    io.PrintLn(ans)

# The Io struct represents the standard input and output streams.
class Io:
    # The constructor of the Io struct initializes the reader and writer attributes.
    def __init__(self):
        self.reader = bufio.Reader(sys.stdin)
        self.writer = bufio.Writer(sys.stdout)
        self.tokens = []
        self.nextToken = 0

    # The Flush method of the Io struct ensures that all output is written before the program exits.
    def Flush(self):
        self.writer.flush()

    # The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
    def NextLine(self):
        buffer = []
        while True:
            line, isPrefix, err = self.reader.readLine()
            if err != None:
                panic(err)
            buffer.append(line)
            if not isPrefix:
                break
        return "".join(buffer)

    # The Next method of the Io struct reads a token from the standard input and returns it as a string.
    def Next(self):
        while self.nextToken >= len(self.tokens):
            line = self.NextLine()
            self.tokens = line.split()
            self.nextToken = 0
        r = self.tokens[self.nextToken]
        self.nextToken += 1
        return r

    # The Int method of the Io struct reads an integer from the standard input and returns it.
    def Int(self):
        i, err = strconv.Atoi(self.Next())
        if err != None:
            panic(err)
        return i

    # The PrintLn method of the Io struct prints a line to the standard output.
    def PrintLn(self, a):
        self.writer.write(a + "\n")

    # The Printf method of the Io struct prints a formatted line to the standard output.
    def Printf(self, format, a):
        self.writer.write(format % a)

    # The PrintIntLn method of the Io struct prints an integer array to the standard output.
    def PrintIntLn(self, a):
        self.PrintLn(a)

    # The PrintStringLn method of the Io struct prints a string array to the standard output.
    def PrintStringLn(self, a):
        self.PrintLn(a)

# The Log function logs a message to the standard error stream.
def Log(name, value):
    print(name + "=" + str(value), file=sys.stderr)

# The Abs function returns the absolute value of an integer.
def Abs(a):
    if a >= 0:
        return a
    else:
        return -a

# The Pow function returns the result of raising a to the power of b.
def Pow(p, q):
    return int(math.pow(p, q))

# The Min function returns the minimum of a list of integers.
def Min(nums):
    if len(nums) == 0:
        panic("funciton min() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = min(res, nums[i])
    return res

# The Max function returns the maximum of a list of integers.
def Max(nums):
    if len(nums) == 0:
        panic("funciton max() requires at least one argument.")
    res = nums[0]
    for i in range(len(nums)):
        res = max(res, nums[i])
    return res

# The SortAsc function sorts an integer slice in ascending order.
def SortAsc(a):
    return sorted(a)

# The SortDesc function sorts an integer slice in descending order.
def SortDesc(a):
    return sorted(a, reverse=True)

# The GCD function returns the greatest common divisor of a and b.
def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a%b)

# The LCM function returns the least common multiple of a and b.
def LCM(a, b):
    if a == 0 and b == 0:
        return 0
    return a * b // GCD(a, b)

# The CumSum function computes the cumulative sum of an integer slice.
def CumSum(nums):
    sums = [0]

    for i in range(len(nums)):
        sums.append(sums[i] + nums[i])
    return sums

# The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
def BisectLeft(nums, left, right, target):
    if left == right:
        if nums[left] == target:
            return left
        elif nums[left] < target:
            return left + 1
        else:
            return left
    mid = (left + right) // 2
    if nums[mid] == target:
        return mid
    elif nums[mid] > target:
        return BisectLeft(nums, left, mid, target)
    else:
        return BisectLeft(nums, mid+1, right, target)

# The Permutations function returns all permutations of a slice.
def Permutations(nums):
    size = len(nums)
    result = []

    for _, n in enumerate(nums):
        rest = remove(nums, n)
        lists = Permutations(rest)
        for _, list in enumerate(lists):
            lists.append(list + [n])
            result.append(lists)
    return result

# The remove function removes the first occurrence of x from a slice.
def remove(nums, x):
    result = []
    for _, n in enumerate(nums):
        if n != x:
            result.append(n)
    return result

# The PowerSet function returns all subsets of a slice.
def PowerSet(nums):
    size = len(nums)
    result = []
    idx = 0

    result.append([])
    idx += 1

    for _, n in enumerate(nums):
        max = idx
        for i in range(max):
            result.append(copyAndAppend(result[i], n))
            idx += 1
    return result

# The copyAndAppend function returns a copy of x with y appended to it.
def copyAndAppend(x, y):
    dst = x[:]
    dst.append(y)
    return dst

# The Combination function returns all combinations of size r from a slice.
def Combination(nums, r):
    size = len(nums)
    result = []
    bi = (1 << uint(r)) - 1
    max = 1 << uint(size)
    idx = 0

    for bi < max:
        flags = bi
        s = []
        for i in range(size):
            if flags % 2 != 0:
                s.append(nums[i])
            flags //= 2
        result.append(s)
        idx += 1
        bi = Combination2NextIndex(bi)
    return result

# The CombinationCount function returns the number of combinations of size r from a slice.
def CombinationCount(n, m, maxInput):
    memo = {}
    for i in range(1, maxInput*maxInput+1):
        memo[i] = {}
    return combinationCount(n, m, memo)

def combinationCount(n, m, memo):
    if n == m or m == 0:
        return 1

    left, lOK = memo[n-1].get(m-1, None)
    right, rOK = memo[n-1].get(m, None)

    if lOK and rOK:
        return left + right

    if lOK:
        right = combinationCount(n-1, m, memo)
        memo[n-1][m] = right
        return left + right

    if rOK:
        left = combinationCount(n-1, m-1, memo)
        memo[n-1][m-1] = left
        return left + right

    left = combinationCount(n-1, m-1, memo)
    right = combinationCount(n-1, m, memo)
    memo[n-1][m-1] = left
    memo[n-1][m] = right
    return left + right

# The Fact function returns the factorial of n.
def Fact(n):
    if n == 0:
        return 1
    else:
        return n * Fact(n-1)

# The Divisors function returns all divisors of n.
def Divisors(n):
    divisors = {}
    for i in range(1, int(math.sqrt(n))+1):
        if n % i == 0:
            divisors[i] = True
            divisors[n//i] = True
    return list(divisors.keys())

# The main function is the entry point of the program.
def main():
    # Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
    io = Io()
    io.Flush()

    # Read the number n from the standard input.
    n = io.Int()

    # Initialize an array aa of length n to store the input integers.
    aa = [0] * n

    # Read n integers from the standard input and store them in the aa array using a for loop.
    for i in range(n):
        aa[i] = io.Int()

    # Compute the cumulative sum of the aa array using the CumSum function.
    cumsum = CumSum(aa)

    # Initialize a variable ans to store the answer.
    ans = 2020202020

    # Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
    for i in range(1, len(cumsum)-1):
        # Compute the absolute difference between the last cumulative sum and the current cumulative sum.
        diff1 = abs(cumsum[len(cumsum)-1] - cumsum[i])

        # Compute the difference between the current cumulative sum and the first cumulative sum.
        diff2 = cumsum[i] - cumsum[0]

        # Keep the minimum of these two 