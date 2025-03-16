import sys
from collections import defaultdict

def read_long_lines(times):
    result = []
    for _ in range(times):
        line = sys.stdin.readline().rstrip('\n')
        result.append(line)
    return result

class Console:
    def __init__(self):
        self.output = []

    def printf(self, format_str, *args):
        self.output.append(format_str % args)

    def println(self, s):
        self.output.append(s)

    def flush(self):
        print("\n".join(self.output))

def print_list(lst):
    con = Console()
    con.printf(" ".join(map(str, lst)))
    con.println("")
    con.flush()

def main():
    con = Console()

    m = set()
    lines = read_long_lines(4)
    a = lines[1].split()
    for num in a:
        n = int(num)
        m.add(n)

    result = []
    b = lines[3].split()
    for num in b:
        n = int(num)
        if n in m:
            m.remove(n)
        else:
            m.add(n)

    result = sorted(m)
    for j in result:
        con.printf("%d\n", j)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
