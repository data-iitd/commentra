
# Reads a single integer from standard input.
def scanInt():
    return int(input())

# Initializes the scanner to split input by words.
def init():
    pass

# Creates a struct to represent an arm with left and right endpoints.
class arm:
    def __init__(self, l, r):
        self.l = l
        self.r = r

# Creates a slice to store the arms.
def make(n):
    return [arm(0, 0) for i in range(n)]

# Reads each arm's range and stores the left and right endpoints.
def readArms(as):
    for i in range(len(as)):
        x, l = scanInt(), scanInt()
        as[i].l = x - l
        as[i].r = x + l

# Sorts the arms based on their right endpoints.
def sortArms(as):
    as.sort(key=lambda x: x.r)

# Initializes the answer and the right endpoint reference.
def initAns(as):
    ans = 1
    r = as[0].r
    return ans, r

# Iterates through the sorted arms to count non-overlapping arms.
def countArms(as):
    ans, r = initAns(as)
    for i in range(1, len(as)):
        if as[i].l >= r:
            ans += 1
            r = as[i].r
    return ans

# Reads the number of arms.
n = scanInt()

# Creates a slice to store the arms.
as = make(n)

# Reads each arm's range and stores the left and right endpoints.
readArms(as)

# Sorts the arms based on their right endpoints.
sortArms(as)

# Counts the number of non-overlapping arms.
ans = countArms(as)

# Prints the count of non-overlapping arms.
print(ans)

