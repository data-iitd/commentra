
# +build ignore
import sys

# I/O
# The Scanner class is defined to read input efficiently.
class Scanner:
    def __init__(self):
        self.sc = iter(sys.stdin.read().split())

    # Reads the next word from the input and returns it as a string.
    def nextStr(self):
        return next(self.sc)

    # Reads the next word, converts it to an integer, and returns it.
    def nextInt(self):
        return int(self.nextStr())

    # Reads the next word, converts it to a float, and returns it.
    def nextFloat(self):
        return float(self.nextStr())

    # Reads the next word and returns it as a byte slice.
    def nextRuneSlice(self):
        return self.nextStr().encode()

    # Reads `n` integers from the input and returns them as a slice.
    def nextIntSlice(self, n):
        return [self.nextInt() for _ in range(n)]

    # Reads `n` floats from the input and returns them as a slice.
    def nextFloatSlice(self, n):
        return [self.nextFloat() for _ in range(n)]

# The run function reads the input, processes it, and prints the result.
def run(input, output):
    sc = Scanner()
    # Reads the number of elements N and the string S.
    N = sc.nextInt()
    S = sc.nextStr()

    if N == 0:
        pass

    if N < 4:
        print(0)
        return 0

    # Counts the number of 'R', 'B', and 'G' characters in S.
    nr = 0
    nb = 0
    ng = 0
    for c in S:
        if c == 'R':
            nr += 1
        elif c == 'B':
            nb += 1
        elif c == 'G':
            ng += 1

    # Calculates the number of triplets where the characters are all different.
    same = 0
    for a in range(1, N):
        i = 0
        j = a
        k = 2 * a
        if k >= N:
            break
        while k < N:
            if S[i]!= S[j] and S[i]!= S[k] and S[j]!= S[k]:
                same += 1
            i += 1
            j += 1
            k += 1

    # Calculates the total number of possible triplets.
    tot = nr * nb * ng

    # Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
    print(tot - same)

    return 0

# The main function calls the run function with standard input and output, and exits with the return value of run.
def main():
    sys.exit(run(sys.stdin, sys.stdout))

# 