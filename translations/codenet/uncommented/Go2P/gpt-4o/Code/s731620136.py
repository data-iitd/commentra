import sys

class Scanner:
    def __init__(self):
        self.sc = sys.stdin.read().split()

    def next_str(self):
        return self.sc.pop(0)

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

def run():
    sc = Scanner()
    N = sc.next_int()
    S = sc.next_str()

    if N < 4:
        print(0)
        return

    nr = nb = ng = 0
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
        j = 1 * a
        k = 2 * a
        if k >= N:
            break
        while k < N:
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                same += 1
            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng
    print(tot - same)

if __name__ == "__main__":
    run()

# <END-OF-CODE>
