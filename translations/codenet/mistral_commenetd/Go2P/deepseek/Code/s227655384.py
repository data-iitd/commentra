import sys

def read_long_lines(times):
    result = []
    for _ in range(times):
        while True:
            line = sys.stdin.readline()
            if not line:
                break
            result.append(line.strip())
            if not line.endswith('\n'):
                break
    return result

class Console:
    def __init__(self):
        self.writer = sys.stdout

    def printf(self, format, *args):
        print(format % args, end='', file=self.writer)

    def println(self, s):
        print(s, file=self.writer)

    def close(self):
        self.flush()

    def flush(self):
        self.writer.flush()

def print_list(lst):
    con = Console()
    for i, num in enumerate(lst):
        if i == 0:
            con.printf("%d", num)
        else:
            con.printf(" %d", num)
    con.println("")

def main():
    con = Console()
    unique_numbers = set()
    lines = read_long_lines(4)
    numbers = list(map(int, lines[1].split()))
    for num in numbers:
        unique_numbers.add(num)

    numbers = list(map(int, lines[3].split()))
    for num in numbers:
        unique_numbers.add(num)

    sorted_numbers = sorted(unique_numbers)
    for num in sorted_numbers:
        con.printf("%d\n", num)

if __name__ == "__main__":
    main()
