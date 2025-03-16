
import sys
from operator import itemgetter

# out is a utility function for printing output, currently commented out.
def out(*args):
    # print(*args)
    pass

# nextString reads the next string from input and returns it.
def nextString():
    return input()

# Data represents a single data entry with a string field.
class Data:
    def __init__(self, x):
        self.x = x

# Datas is a slice of Data, implementing sort.Interface.
class Datas(list):
    def __init__(self, data):
        super().__init__(data)

    def __lt__(self, other):
        return self.x < other.x

def main():
    sc = iter(sys.stdin.read().split())
    N = int(next(sc))
    L = int(next(sc))
    s = [Data(next(sc)) for _ in range(N)]

    out(N, L, s)
    s.sort()
    out(s)

    ans = ''.join(d.x for d in s)
    print(ans)

