import sys

class Scanner:
    def __init__(self):
        self.buffer = []
        self.position = 0

    def next(self):
        self.pre()
        start = self.position
        while self.position < len(self.buffer):
            if self.buffer[self.position] == ' ':
                break
            self.position += 1
        result = ''.join(self.buffer[start:self.position])
        self.position += 1  # Move past the space
        return result

    def next_line(self):
        self.pre()
        start = self.position
        self.position = len(self.buffer)
        return ''.join(self.buffer[start:])

    def next_int(self):
        return int(self.next())

    def next_int_array(self):
        self.pre()
        start = self.position
        result = []
        while self.position < len(self.buffer) + 1:
            if self.position == len(self.buffer) or self.buffer[self.position] == ' ':
                v = int(''.join(self.buffer[start:self.position]))
                result.append(v)
                start = self.position + 1
            self.position += 1
        return result

    def pre(self):
        if self.position >= len(self.buffer):
            self.read_line()
            self.position = 0

    def read_line(self):
        self.buffer = list(sys.stdin.readline().strip())

def main():
    sc = Scanner()
    S = sc.next()
    
    if S.startswith("YAKI"):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
