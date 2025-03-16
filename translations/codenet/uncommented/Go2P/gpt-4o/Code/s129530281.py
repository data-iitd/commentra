import sys

class Segment:
    def __init__(self, n):
        self.n = n
        self.unit = [1]
        self.bucket = [[]]
        self.chunk = 8
        self.init(n)

    def init(self, n):
        self.bucket[0] = [0] * n
        while n > 1:
            n = (n - 1) // self.chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[-1] * self.chunk)
        self.h = len(self.unit)

    def maximize(self, index, value):
        self.bucket[0][index] = value
        for i in range(self.h - 1):
            s = index - index % self.chunk
            t = s + self.chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i])
            parent = index // self.chunk
            max_value = 0
            for j in range(s, t):
                if max_value < self.bucket[i][j]:
                    max_value = self.bucket[i][j]
            self.bucket[i + 1][parent] = max_value
            index //= self.chunk

    def top(self):
        index = 0
        for i in range(self.h - 2, -1, -1):
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i])
            for j in range(s, t):
                if self.bucket[i][j] == self.bucket[i + 1][index]:
                    index = j
                    break
        return index

def get_next_int(scanner):
    return int(scanner.readline().strip())

def main():
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as fp:
            scanner = fp
    else:
        scanner = sys.stdin

    n = get_next_int(scanner)
    m = get_next_int(scanner)
    seg = Segment(n)

    for i in range(n):
        seg.maximize(i, get_next_int(scanner))

    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] // 2)

    ans = sum(seg.bucket[0])
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
