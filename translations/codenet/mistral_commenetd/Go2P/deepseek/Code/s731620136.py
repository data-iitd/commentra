import sys

# I/O
class Scanner:
    def __init__(self, input):
        self.sc = input

    def next_int(self):
        return int(self.sc.readline().strip())

    def next_line(self):
        return self.sc.readline().strip()

def run(input, output):
    sc = Scanner(input)
    N = sc.next_int()

    if N == 0:
        print(0, file=output)
        return 0

    S = sc.next_line()

    nr, nb, ng = 0, 0, 0

    for c in S:
        if c == 'R':
            nr += 1
        elif c == 'B':
            nb += 1
        elif c == 'G':
            ng += 1

    same = 0

    for a in range(1, N):
        i = 0
        j = a
        k = 2 * a

        while k < N:
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                same += 1
            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng
    print(tot - same, file=output)

    return 0

def main():
    run(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()
