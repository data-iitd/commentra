
# I/O
class Scanner:
    def __init__(self):
        self.sc = bufio.Scanner(sys.stdin)
        self.sc.split(bufio.ScanWords)
        self.sc.buffer(make([]byte, 1024), int(1e+9)) # Buffer size for efficient reading

    def nextStr(self):
        self.sc.scan()
        return self.sc.text()

    def nextInt(self):
        i, e = strconv.Atoi(self.nextStr())
        if e != nil:
            panic(e)
        return i

    def nextFloat(self):
        f, e = strconv.ParseFloat(self.nextStr(), 64)
        if e != nil:
            panic(e)
        return f

    def nextRuneSlice(self):
        return []rune(self.nextStr())

    def nextIntSlice(self, n):
        res = make([]int, n)
        for i := 0; i < n; i++ {
            res[i] = self.nextInt()
        }
        return res

    def nextFloatSlice(self, n):
        res = make([]float64, n)
        for i := 0; i < n; i++ {
            res[i] = self.nextFloat()
        }
        return res

# Arithmetic
def max(nums):
    m = nums[0]
    for i in nums:
        if m < i:
            m = i
    return m

def min(nums):
    m = nums[0]
    for i in nums:
        if m > i:
            m = i
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

def ceil(a, b):
    if a % b == 0:
        return a / b
    else:
        return a/b + 1

# Sort
class RuneSlice(list):
    def __lt__(self, other):
        return self[0] < other[0]

# Main
MOD = int(1e+9) + 7 # Modulus value for modular arithmetic
INF = 1 << 60      # Infinite value for comparison

# Mon represents a monster with x-coordinate and height
class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Mons is a slice of Mon structures
class Mons(list):
    def __lt__(self, other):
        return self[0].x < other[0].x

# Node represents a node in the priority queue with x-coordinate and damage
class Node:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Queue is a priority queue implemented as a slice with custom push, pop, and isEmpty functions
class Queue:
    def __init__(self):
        self.arr = []

    def push(self, v):
        self.arr.append(v)

    def first(self):
        return self.arr[0]

    def pop(self):
        res = self.arr[0]
        self.arr = self.arr[1:]
        return res

    def isEmpty(self):
        return len(self.arr) == 0

# Main function initializes variables, sorts monsters, and calculates the answer
def main():
    # Initialize a new Scanner and a bufio.Writer for input/output
    sc = Scanner()
    wtr = bufio.Writer(sys.stdout)

    # Read input values N, D, and A from the scanner
    N, D, A = sc.nextInt(), sc.nextInt(), sc.nextInt()

    # Initialize a slice of Mon structures called M
    M = [Mon(sc.nextInt(), sc.nextInt()) for _ in range(N)]

    # Sort the M slice based on x-coordinates
    M.sort()

    # Initialize an empty priority queue called q
    q = Queue()

    # Initialize answer variable ans to 0 and total variable total to 0
    ans = 0
    total = 0

    # Iterate through each Mon in the sorted M slice
    for i in range(N):
        # Current Mon
        m = M[i]

        # While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
        while not q.isEmpty() and q.first().x < m.x:
            # Pop the first Node from the priority queue
            total -= q.pop().h

        # If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
        if total < m.h:
            damage = m.h - total
            ans += damage
            q.push(Node(m.x + 2*D, damage))
            total += damage

    # Print the answer
    print(ans)

    # Flush the writer to output the answer
    wtr.flush()

