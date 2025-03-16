import sys
from collections import Counter

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.tokens = []

    def read(self):
        while not self.tokens:
            line = sys.stdin.readline()
            self.tokens = line.split()
        token = self.tokens.pop(0)
        return token

    def next_int(self):
        return int(self.read())

    def next_long(self):
        return int(self.read())

    def next_double(self):
        return float(self.read())

    def next_line(self):
        return sys.stdin.readline().strip()

class Task:
    def solve(self, reader, writer):
        n = reader.next_int()
        array = [0] * 1001
        for _ in range(n):
            index = reader.next_int()
            array[index] += 1
        count_max = max(array)
        if n % 2 == 0:
            if count_max <= n // 2:
                writer.write("YES\n")
            else:
                writer.write("NO\n")
        else:
            if count_max <= n // 2 + 1:
                writer.write("YES\n")
            else:
                writer.write("NO\n")

# Main function to run the program
def main():
    reader = InputReader(sys.stdin)
    writer = sys.stdout
    task = Task()
    task.solve(reader, writer)

if __name__ == "__main__":
    main()
