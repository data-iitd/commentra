
import sys
from operator import itemgetter

# out is a utility function to print multiple values with a newline.
def out(*args, end='\n'):
    print(*args, end=end)

# Read input from stdin and parse to integer.
def read_int():
    return int(input())

# Read input from stdin and parse to string.
def read_str():
    return input().strip()

# Read input from stdin and parse to list of strings.
def read_strings():
    return read_str().split()

# Read input from stdin and parse to list of integers.
def read_ints():
    return list(map(int, read_strings()))

# Data represents a structure holding a string.
class Data:
    def __init__(self, x):
        self.x = x

# Datas is a slice of Data structures.
class Datas(list):
    def __init__(self, data):
        super().__init__(data)

    def __lt__(self, other):
        return self.x < other.x

# The main function reads N strings, sorts them, and prints the concatenated result.
def main():
    N, L = read_ints()
    s = [Data(read_str()) for _ in range(N)]

    out(N, L, s)
    s.sort()
    out(s)

    ans = ''.join(d.x for d in s)
    out(ans)

# Call the main function.
if __name__ == '__main__':
    main()

