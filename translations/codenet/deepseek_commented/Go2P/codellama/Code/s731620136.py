
# +build ignore
import sys

# I/O
# The Scanner struct is defined to read input efficiently.
class Scanner:
    sc = None

    def __init__(self):
        self.sc = sys.stdin

    def nextStr(self):
        return self.sc.readline().strip()

    def nextInt(self):
        return int(self.nextStr())

    def nextFloat(self):
        return float(self.nextStr())

    def nextRuneSlice(self):
        return list(self.nextStr())

    def nextIntSlice(self, n):
        return [self.nextInt() for i in range(n)]

    def nextFloatSlice(self, n):
        return [self.nextFloat() for i in range(n)]

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
    nr, nb, ng = 0, 0, 0
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
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
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