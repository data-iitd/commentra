import sys

def get_next_line():
    return sys.stdin.readline().strip()

def get_next_int():
    return int(get_next_line())

def get_next_int_list():
    return [int(x) for x in get_next_line().split()]

def get_next_int_list_list():
    return [get_next_int_list() for _ in range(get_next_int())]

class Segment:
    def __init__(self, n):
        self.n = n
        self.unit = [1]
        self.bucket = [[0] * n]
        self.h = 1
        self.chunk = 8
        while n > 1:
            n = (n-1)/self.chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[-1] * self.chunk)
            self.h += 1

    def maximize(self, index, value):
        self.bucket[0][index] = value
        for i in range(self.h-1):
            s = index - index%self.chunk
            t = s + self.chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i])
            parent = index / self.chunk
            max = 0
            for i in range(s, t):
                if max < self.bucket[i]:
                    max = self.bucket[i]
            self.bucket[i+1][parent] = max
            index /= self.chunk

    def top(self):
        index = 0
        for i in range(self.h-2, -1, -1):
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i])
            for i in range(s, t):
                if self.bucket[i] == self.bucket[i+1][index]:
                    index = i
                    break
        return index

def main():
    n = get_next_int()
    m = get_next_int()
    seg = Segment(n)
    for i in range(n):
        seg.maximize(i, get_next_int())
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1)

    ans = 0
    for i in range(n):
        ans += seg.bucket[0][i]
    print(ans)

if __name__ == "__main__":
    main()

# 