
# Initialize logger to include short file names
import logging
logging.basicConfig(filename='log.txt', level=logging.INFO, filemode='w', format='%(asctime)s - %(levelname)s - %(message)s')

# Create a new scanner to read input
class scanner:
    def __init__(self):
        self.r = open('input.txt', 'r')
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for i in range(self.p, len(self.buf)):
            if self.buf[i] == ' ':
                break
        result = ''.join(self.buf[start:i])
        self.p = i + 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def nextInt(self):
        return int(self.next())

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for line in self.r:
            self.buf.append(line)

# Read two integers from the input
sc = scanner()
x = sc.nextInt()
y = sc.nextInt()

# Define an array containing three slices, each representing a group of months with the same number of days
a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

# Iterate over the array to determine which group each of the integers belongs to
xt = 0
yt = 0
for i, t in enumerate(a):
    for n in t:
        # logging.info(n) # Uncomment to log each number in the array
        if x == n:
            xt = i
        if y == n:
            yt = i

# Compare the groups of x and y to determine if they belong to the same group
if xt == yt:
    print("Yes")
else:
    print("No")

