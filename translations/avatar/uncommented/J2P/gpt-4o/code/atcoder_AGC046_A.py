import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            result = self.data[self.index]
            self.index += 1
            return result
        return None

    def next_int(self):
        return int(self.next())

def main():
    sc = FastReader()
    x = sc.next_int()
    count = 0
    tmp = x
    x = 0
    while x != 360:
        x += tmp
        if x > 360:
            x -= 360
        count += 1
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
