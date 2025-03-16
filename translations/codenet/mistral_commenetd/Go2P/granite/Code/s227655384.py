

import sys

def read_long_lines(times):
    result = []
    for i in range(times):
        line = sys.stdin.readline()
        result.append(line)
    return result

class Console:
    def __init__(self):
        self.writer = sys.stdout

    def printf(self, format, *args):
        self.writer.write(format.format(*args))

    def println(self, s):
        self.writer.write(s + '\n')

    def flush(self):
        self.writer.flush()

def print_list(list):
    con = Console()
    for i in range(len(list)):
        if i == 0:
            con.printf("%d", list[i])
        else:
            con.printf(" %d", list[i])
    con.println("")

if __name__ == "__main__":
    con = Console()
    lines = read_long_lines(4)
    a = lines[1].split()
    m = set()
    for i in range(len(a)):
        m.add(int(a[i]))
    b = lines[3].split()
    for i in range(len(b)):
        m.add(int(b[i]))
    result = list(m)
    result.sort()
    for j in range(len(result)):
        con.printf("%d\n", result[j])

