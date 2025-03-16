
# I/O
class Scanner:
    sc = None

    def __init__(self):
        self.sc = bufio.Scanner(sys.stdin)
        self.sc.split(bufio.ScanWords)
        self.sc.buffer(bytearray(1024), int(1e+9))

    def nextStr(self):
        self.sc.scan()
        return self.sc.text()

    def nextInt(self):
        return int(self.nextStr())

    def nextFloat(self):
        return float(self.nextStr())

    def nextRuneSlice(self):
        return list(self.nextStr())

    def nextIntSlice(self, n):
        res = []
        for i in range(n):
            res.append(self.nextInt())
        return res

    def nextFloatSlice(self, n):
        res = []
        for i in range(n):
            res.append(self.nextFloat())
        return res

# Arithmetic
def max(nums):
    m = nums[0]
    for i in range(1, len(nums)):
        if m < nums[i]:
            m = nums[i]
    return m

def min(nums):
    m = nums[0]
    for i in range(1, len(nums)):
        if m > nums[i]:
            m = nums[i]
    return m

def abs(x):
    if x > 0:
        return x
    return -x

def pow(x, y):
    res = 1
    for i in range(y):
        res *= x
    return res

# Sort
class Val:
    id = 0
    num = 0

class ByNum(list):
    def __init__(self, vals):
        super().__init__(vals)

    def __lt__(self, other):
        return self.num < other.num

# Main function
def main():
    sc = Scanner()
    wtr = bufio.Writer(sys.stdout)

    # Read input values
    A, B, C, K = sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()

    # Find the maximum value among A, B, and C
    ma = max([A, B, C])

    # Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    # Calculate the final answer
    answer = pow(ma, K) + rest

    # Write the answer to the output
    print(answer, file=wtr)
    wtr.flush()

if __name__ == "__main__":
    main()

