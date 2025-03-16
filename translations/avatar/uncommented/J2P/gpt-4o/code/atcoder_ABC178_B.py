import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        result = self.data[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.data[self.index]

def main():
    reader = FastReader()
    a = [reader.next_long() for _ in range(4)]
    result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
