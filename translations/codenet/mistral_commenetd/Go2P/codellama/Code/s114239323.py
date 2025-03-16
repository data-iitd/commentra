
# Package main is the entry point of the program
import sys

# main function is the entry point of the program
def main():
    # Read the number of test cases N from standard input
    N = int(sys.stdin.readline())

    # Read an array h of N integers from standard input
    h = [int(x) for x in sys.stdin.readline().split()]

    # Initialize a dp array of size N with zeros
    dp = [0] * N

    # Set the first element of dp to the absolute difference between the first and second elements of h
    dp[1] = abs(h[0] - h[1])

    # Iterate over the array h from the second element to the last
    for i in range(2, N):
        # Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))

    # Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
    print(dp[N - 1])

# Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
def max(a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

def min(a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

def sum(a):
    r = 0
    for i in range(len(a)):
        r += a[i]
    return r

def abs(a):
    if a < 0:
        return -a
    return a

# Helper function to read input from standard input as a single string
def nextReader():
    return sys.stdin.readline().strip()

# Helper function to read a single string from standard input
def nextString():
    return nextReader()

# Helper function to read a single integer from standard input
def nextInt():
    return int(nextReader())

# Helper function to read an array of N integers from standard input
def nextInts(n):
    return [int(x) for x in nextReader().split()]

# Helper function to read a single float from standard input
def nextFloat():
    return float(nextReader())

# Helper function to read an array of N floats from standard input
def nextFloats(n):
    return [float(x) for x in nextReader().split()]

# Helper function to read a single complex number from standard input
def nextComplex():
    return complex(nextReader())

# Helper function to read an array of N complex numbers from standard input
def nextComplexs(n):
    return [complex(x) for x in nextReader().split()]

# Helper function to read a single boolean from standard input
def nextBoolean():
    return nextReader() == "True"

# Helper function to read an array of N booleans from standard input
def nextBooleans(n):
    return [nextReader() == "True" for i in range(n)]

# Helper function to read a single character from standard input
def nextCharacter():
    return nextReader()[0]

# Helper function to read an array of N characters from standard input
def nextCharacters(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single line from standard input
def nextLine():
    return nextReader()

# Helper function to read an array of N lines from standard input
def nextLines(n):
    return [nextReader() for i in range(n)]

# Helper function to read a single byte from standard input
def nextByte():
    return nextReader()[0]

# Helper function to read an array of N bytes from standard input
def nextBytes(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single rune from standard input
def nextRune():
    return nextReader()[0]

# Helper function to read an array of N runes from standard input
def nextRunes(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big integer from standard input
def nextBigInt():
    return int(nextReader())

# Helper function to read an array of N big integers from standard input
def nextBigInts(n):
    return [int(x) for x in nextReader().split()]

# Helper function to read a single big float from standard input
def nextBigFloat():
    return float(nextReader())

# Helper function to read an array of N big floats from standard input
def nextBigFloats(n):
    return [float(x) for x in nextReader().split()]

# Helper function to read a single big complex number from standard input
def nextBigComplex():
    return complex(nextReader())

# Helper function to read an array of N big complex numbers from standard input
def nextBigComplexs(n):
    return [complex(x) for x in nextReader().split()]

# Helper function to read a single big boolean from standard input
def nextBigBoolean():
    return nextReader() == "True"

# Helper function to read an array of N big booleans from standard input
def nextBigBooleans(n):
    return [nextReader() == "True" for i in range(n)]

# Helper function to read a single big character from standard input
def nextBigCharacter():
    return nextReader()[0]

# Helper function to read an array of N big characters from standard input
def nextBigCharacters(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big line from standard input
def nextBigLine():
    return nextReader()

# Helper function to read an array of N big lines from standard input
def nextBigLines(n):
    return [nextReader() for i in range(n)]

# Helper function to read a single big byte from standard input
def nextBigByte():
    return nextReader()[0]

# Helper function to read an array of N big bytes from standard input
def nextBigBytes(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big rune from standard input
def nextBigRune():
    return nextReader()[0]

# Helper function to read an array of N big runes from standard input
def nextBigRunes(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big integer from standard input
def nextBigInt64():
    return int(nextReader())

# Helper function to read an array of N big integers from standard input
def nextBigInts64(n):
    return [int(x) for x in nextReader().split()]

# Helper function to read a single big float from standard input
def nextBigFloat64():
    return float(nextReader())

# Helper function to read an array of N big floats from standard input
def nextBigFloats64(n):
    return [float(x) for x in nextReader().split()]

# Helper function to read a single big complex number from standard input
def nextBigComplex128():
    return complex(nextReader())

# Helper function to read an array of N big complex numbers from standard input
def nextBigComplexs128(n):
    return [complex(x) for x in nextReader().split()]

# Helper function to read a single big boolean from standard input
def nextBigBoolean64():
    return nextReader() == "True"

# Helper function to read an array of N big booleans from standard input
def nextBigBooleans64(n):
    return [nextReader() == "True" for i in range(n)]

# Helper function to read a single big character from standard input
def nextBigCharacter64():
    return nextReader()[0]

# Helper function to read an array of N big characters from standard input
def nextBigCharacters64(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big line from standard input
def nextBigLine64():
    return nextReader()

# Helper function to read an array of N big lines from standard input
def nextBigLines64(n):
    return [nextReader() for i in range(n)]

# Helper function to read a single big byte from standard input
def nextBigByte64():
    return nextReader()[0]

# Helper function to read an array of N big bytes from standard input
def nextBigBytes64(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big rune from standard input
def nextBigRune64():
    return nextReader()[0]

# Helper function to read an array of N big runes from standard input
def nextBigRunes64(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big integer from standard input
def nextBigInt32():
    return int(nextReader())

# Helper function to read an array of N big integers from standard input
def nextBigInts32(n):
    return [int(x) for x in nextReader().split()]

# Helper function to read a single big float from standard input
def nextBigFloat32():
    return float(nextReader())

# Helper function to read an array of N big floats from standard input
def nextBigFloats32(n):
    return [float(x) for x in nextReader().split()]

# Helper function to read a single big complex number from standard input
def nextBigComplex64():
    return complex(nextReader())

# Helper function to read an array of N big complex numbers from standard input
def nextBigComplexs64(n):
    return [complex(x) for x in nextReader().split()]

# Helper function to read a single big boolean from standard input
def nextBigBoolean32():
    return nextReader() == "True"

# Helper function to read an array of N big booleans from standard input
def nextBigBooleans32(n):
    return [nextReader() == "True" for i in range(n)]

# Helper function to read a single big character from standard input
def nextBigCharacter32():
    return nextReader()[0]

# Helper function to read an array of N big characters from standard input
def nextBigCharacters32(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big line from standard input
def nextBigLine32():
    return nextReader()

# Helper function to read an array of N big lines from standard input
def nextBigLines32(n):
    return [nextReader() for i in range(n)]

# Helper function to read a single big byte from standard input
def nextBigByte32():
    return nextReader()[0]

# Helper function to read an array of N big bytes from standard input
def nextBigBytes32(n):
    return [nextReader()[0] for i in range(n)]

# Helper function to read a single big rune from standard input
def nextBigRune32():
    return nextReader()[0]

# Helper function to read an array of N big runes from standard inpu