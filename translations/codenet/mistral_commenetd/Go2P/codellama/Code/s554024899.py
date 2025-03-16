
import sys

def main():
    # Initialize a new scanner object
    sc = Scanner()

    # Read the first two integers from the standard input using the scanner
    x = sc.nextInt()
    y = sc.nextInt()

    # Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    xt, yt = 0, 0

    # Define a 3x3 2D array a
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

    # Iterate through each inner loop of the outer loop
    for i, t in enumerate(a):
        # Iterate through each element of the current inner loop
        for j, n in enumerate(t):
            # Check if the current element is equal to x, if yes, store its index in xt
            if x == n:
                xt = i
            # Check if the current element is equal to y, if yes, store its index in yt
            if y == n:
                yt = i

    # Check if the indices xt and yt are equal, if yes, print "Yes"
    if xt == yt:
        print("Yes")
    else:
        print("No")

# Define a scanner structure
class Scanner:
    # Initialize a new scanner object
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    # Function to read a single word from the input
    def next(self):
        self.pre()
        start = self.p
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                break
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    # Function to read a line from the input
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    # Function to read an integer from the input
    def nextInt(self):
        return int(self.next())

    # Function to prepare the scanner for the next input
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # Function to read a line from the input
    def readLine(self):
        self.buf = []
        while True:
            l, p, e = self.r.readline()
            if e != None:
                raise e
            self.buf.append(l)
            if not p:
                break

# Helper function to find the maximum of two integers
def max(a, b):
    if a > b:
        return a
    return b

# Helper function to find the minimum of two integers
def min(a, b):
    if a < b:
        return a
    return b

# Helper function to find the absolute value of an integer
def abs(a):
    if a < 0:
        return -a
    return a

# Helper function to find the absolute value of a float
def fabs(a):
    if a < 0:
        return -a
    return a

# Helper function to find the square of an integer
def sqr(a):
    return a * a

# Helper function to find the square of a float
def fsqr(a):
    return a * a

# Helper function to find the cube of an integer
def cube(a):
    return a * a * a

# Helper function to find the cube of a float
def fcube(a):
    return a * a * a

# Helper function to find the power of an integer
def pow(a, b):
    result = 1
    for i in range(b):
        result *= a
    return result

# Helper function to find the power of a float
def fpow(a, b):
    result = 1
    for i in range(b):
        result *= a
    return result

# Helper function to find the factorial of an integer
def fact(a):
    result = 1
    for i in range(1, a + 1):
        result *= i
    return result

# Helper function to find the factorial of a float
def ffact(a):
    result = 1
    for i in range(1, int(a) + 1):
        result *= i
    return result

# Helper function to find the modulo of two integers
def mod(a, b):
    return a % b

# Helper function to find the modulo of two floats
def fmod(a, b):
    return a % b

# Helper function to find the remainder of two integers
def rem(a, b):
    return a % b

# Helper function to find the remainder of two floats
def frem(a, b):
    return a % b

# Helper function to find the gcd of two integers
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Helper function to find the gcd of two floats
def fgcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Helper function to find the lcm of two integers
def lcm(a, b):
    return a * b // gcd(a, b)

# Helper function to find the lcm of two floats
def flcm(a, b):
    return a * b // gcd(a, b)

# Helper function to find the floor of a float
def floor(a):
    return int(a)

# Helper function to find the ceil of a float
def ceil(a):
    return int(a) + 1

# Helper function to find the round of a float
def round(a):
    return int(a + 0.5)

# Helper function to find the trunc of a float
def trunc(a):
    return int(a)

# Helper function to find the frac of a float
def frac(a):
    return a - int(a)

# Helper function to find the sqrt of an integer
def isqrt(a):
    x = a
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + a // x) // 2
    return x

# Helper function to find the sqrt of a float
def fsqrt(a):
    x = a
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + a // x) // 2
    return x

# Helper function to find the cbrt of an integer
def icbrt(a):
    x = a
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + a // (x * x)) // 2
    return x

# Helper function to find the cbrt of a float
def fcbrt(a):
    x = a
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + a // (x * x)) // 2
    return x

# Helper function to find the log of an integer
def ilog(a, b):
    return int(a / b)

# Helper function to find the log of a float
def flog(a, b):
    return a / b

# Helper function to find the log2 of an integer
def ilog2(a):
    return int(a.bit_length() - 1)

# Helper function to find the log2 of a float
def flog2(a):
    return a.bit_length() - 1

# Helper function to find the log10 of an integer
def ilog10(a):
    return int(math.log10(a))

# Helper function to find the log10 of a float
def flog10(a):
    return math.log10(a)

# Helper function to find the exp of an integer
def iexp(a):
    return int(math.exp(a))

# Helper function to find the exp of a float
def fexp(a):
    return math.exp(a)

# Helper function to find the sin of an integer
def isin(a):
    return int(math.sin(a))

# Helper function to find the sin of a float
def fsin(a):
    return math.sin(a)

# Helper function to find the cos of an integer
def icos(a):
    return int(math.cos(a))

# Helper function to find the cos of a float
def fcos(a):
    return math.cos(a)

# Helper function to find the tan of an integer
def itan(a):
    return int(math.tan(a))

# Helper function to find the tan of a float
def ftan(a):
    return math.tan(a)

# Helper function to find the asin of an integer
def iasin(a):
    return int(math.asin(a))

# Helper function to find the asin of a float
def fasin(a):
    return math.asin(a)

# Helper function to find the acos of an integer
def iacos(a):
    return int(math.acos(a))

# Helper function to find the acos of a float
def facos(a):
    return math.acos(a)

# Helper function to find the atan of an integer
def iatan(a):
    return int(math.atan(a))

# Helper function to find the atan of a float
def fatan(a):
    return math.atan(a)

# Helper function to find the sinh of an integer
def isinh(a):
    return int(math.sinh(a))

# Helper function to find the sinh of a float
def fsinh(a):
    return math.sinh(a)

# Helper function to find the cosh of an integer
def icosh(a):
    return int(math.cosh(a))

# Helper function to find the cosh of a float
def fcosh(a):
    return math.cosh(a)

# Helper function to find the tanh of an integer
def itanh(a):
    return int(math.tanh(a))

# Helper function to find the tanh of a float
def ftanh(a):
    return math.tanh(a)

# Helper function to find the asinh of an integer
def iasinh(a):
    return int(math.asinh(a))

# Helper function to find the asinh of a float
def fasinh(a):
    return math.asinh(a)

# Helper function to find the acosh of an integer
def iacosh(a):
    return int(math.acosh(a))

# Helper function to find the acosh of a float
def facosh(a):
    return math.acosh(a)

# Helper function to find the atanh of an integer
def iatanh(a):
    return int(math.atanh(a))

# Helper function to find the atanh of a float
def fatanh(a):
    return math.atanh(a)

# Helper function to find the erf of an integer
def ierf(a):
    return int(math.erf(a))

# Helper function to find the erf of a float
def ferf(a):
    return math.erf(a)

# Helper function to find the erfc of an integer
def ierfc(a):
    return int(math.erfc(a))

# Helper function to find the erfc of a float
def ferfc(a):
    return math.erfc(a)

# Helper function to find the gamma of an integer
def igamma(a):
    return int(math.gamma(a))

# Helper function to find the gamma of a float
def fgamma(a):
    return math.gamma(a)

# Helper function to find the lgamma of an integer
def ilgamma(a):
    return int(math.lgamma(a))

# Helper function to find the lgamma of a float
def flgamma(a):
    return math.lgamma(a)

# Helper function to find the pi of an integer
def ipi(a):
    return int(math.pi)

# Helper function to find the pi of a float
def fpi(a):
    return math.pi

# Helper function to find the e of an integer
def ie(a):
    return int(math.e)

# Helper function to find the e of a float
def fe(a):
    return math.e

# Helper function to find the tau of an integer
def itau(a):
    return int(math.tau)

# Helper function to find the tau of a float
def ftau(a):
    return math.tau

# Helper function to find the inf of an integer
def iinf(a):
    return int(math.inf)

# Helper function to find the inf of a float
def finf(a):
    return math.inf

# Helper function to find the nan of an integer
def inan(a):
    return int(math.nan)

# Helper function to find the nan of a float
def fnan(a):
    return math.nan

# Helper function to find the epsilon of an integer
def iepsilon(a):
    return int(math.epsilon)

# Helper function to find the epsilon of a flo