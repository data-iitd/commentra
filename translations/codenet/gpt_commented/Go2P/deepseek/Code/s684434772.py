MOD = 10**9 + 7

def combi(n, k):
    min_val = (k - 1) * k // 2
    max_val = (2 * n - k + 1) * k // 2
    return max_val - min_val + 1

def main():
    sc = Scanner()
    n = sc.read_int()
    k = sc.read_int()
    total = 0
    for i in range(k, n + 2):
        total += combi(n, i)
        total %= MOD
    print(total)

class Scanner:
    def __init__(self):
        self.buf_reader = sys.stdin

    def read_word(self):
        return self.buf_reader.readline().strip()

    def read_int(self):
        return int(self.read_word())

    def read_int64(self):
        return int(self.read_word())

if __name__ == "__main__":
    main()
