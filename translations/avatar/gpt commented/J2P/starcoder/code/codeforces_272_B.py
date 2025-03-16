
# <START-OF-CODE>

# Initialize FastReader for input and PrintWriter for output
sc = FastReader()
out = PrintWriter(sys.stdout)

# Read the number of integers to process
n = sc.nextInt()

# Array to count occurrences of integers based on their bit count
a = [0] * 33

# Process each integer and count how many have the same number of set bits
for i in range(n):
    a[rec(sc.nextInt())] += 1

# Variable to accumulate the final answer
answer = 0

# Calculate the contribution to the answer from each bit count
for i in range(33):
    summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
    answer += summ

# Print the final answer as a long integer
out.println(int(answer))
out.close()

# Method to count the number of set bits (1s) in the binary representation of x
def rec(x):
    answer = 0
    # Iterate through each bit position from 31 to 0
    for k in range(31, -1, -1):
        # Check if the k-th bit is set
        if (x & (1 << k))!= 0:
            answer += 1
    return answer

# FastReader class for efficient input reading
class FastReader:
    def __init__(self):
        self.buf = []
        self.s = ''

    def init(self):
        self.buf = []
        self.s = ''

    def readline(self):
        while True:
            if self.s == '':
                try:
                    self.s = input()
                except:
                    break
            line = self.s
            self.s = ''
            return line

    def read(self):
        while True:
            if self.s == '':
                try:
                    self.s = input()
                except:
                    break
            c = self.s[0]
            self.s = self.s[1:]
            return c

    def nextInt(self):
        c = self.read()
        while c.isspace():
            c = self.read()
        if c == '-':
            sign = -1
            c = self.read()
        else:
            sign = 1
        ret = 0
        while c.isdigit():
            ret = ret * 10 + int(c)
            c = self.read()
        return sign * ret

    def nextLong(self):
        c = self.read()
        while c.isspace():
            c = self.read()
        if c == '-':
            sign = -1
            c = self.read()
        else:
            sign = 1
        ret = 0
        while c.isdigit():
            ret = ret * 10 + int(c)
            c = self.read()
        return sign * ret

    def nextDouble(self):
        c = self.read()
        while c.isspace():
            c = self.read()
        ret = 0
        dot = 0
        while c.isdigit():
            ret = ret * 10 + int(c)
            c = self.read()
        if c == '.':
            c = self.read()
            while c.isdigit():
                ret += int(c) * pow(10, -dot-1)
                dot += 1
                c = self.read()
        return ret * sign

# 