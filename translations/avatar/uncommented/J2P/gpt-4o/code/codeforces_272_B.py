import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle long values

    def next_double(self):
        return float(self.next())

def rec(x):
    answer = 0
    for k in range(31, -1, -1):
        if (x & (1 << k)) != 0:
            answer += 1
    return answer

def main():
    sc = FastReader()
    n = sc.next_int()
    a = [0] * 33
    for _ in range(n):
        a[rec(sc.next_long())] += 1

    answer = 0.0
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
        answer += summ

    print(int(answer))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
