
import sys

# Initialize logger to include short file names
log = logging.getLogger(__name__)
log.setLevel(logging.DEBUG)

# Create a new scanner to read input
sc = Scanner()

# Read two integers from the input
x = sc.nextInt()
y = sc.nextInt()

# Define an array containing three slices, each representing a group of months with the same number of days
xt = yt = -1
a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

# Iterate over the array to determine which group each of the integers belongs to
for i, t in enumerate(a):
    for n in t:
        # log.debug(n) # Uncomment to log each number in the array
        if x == n:
            xt = i
        if y == n:
            yt = i

# Compare the groups of x and y to determine if they belong to the same group
if xt == yt:
    print("Yes")
else:
    print("No")

# Custom scanner class to read input
class Scanner:
    def __init__(self):
        self.rdr = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 1000)
        self.buf = ""
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = self.buf[start:self.p]
        self.p += 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def nextInt(self):
        v = int(self.next())
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = self.rdr.readline()

# End of code
