class FastScanner:
    def __init__(self):
        import sys
        self.input = sys.stdin.read

    def next_line(self):
        import re
        return re.split('[\n ]', self.input().strip())

    def next_int(self):
        return int(self.next_line()[0])

    def next_long(self):
        return int(self.next_line()[0])

    def next_double(self):
        return float(self.next_line()[0])


def main():
    input = FastScanner()

    n = input.next_int()
    map = {}

    for i in range(n):
        val = input.next_int()
        if val in map:
            map[val] += 1
        else:
            map[val] = 1

    max_count = 0
    for value in map.values():
        max_count = max(max_count, value)

    print(f"{max_count} {len(map)}")


main()
