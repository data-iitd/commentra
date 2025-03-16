
import sys

def out(x):
    #    print(x)

def nextInt():
    return int(sys.stdin.readline())

def nextString():
    return sys.stdin.readline().strip()

# Data :
class Data:
    def __init__(self, x):
        self.x = x

# Datas :
class Datas:
    def __init__(self, datas):
        self.datas = datas

    def __len__(self):
        return len(self.datas)

    def __getitem__(self, i):
        return self.datas[i]

    def __setitem__(self, i, x):
        self.datas[i] = x

    def __lt__(self, other):
        return self.datas[0].x < other.datas[0].x

    def __gt__(self, other):
        return self.datas[0].x > other.datas[0].x

    def __eq__(self, other):
        return self.datas[0].x == other.datas[0].x

    def __ne__(self, other):
        return self.datas[0].x != other.datas[0].x

    def __le__(self, other):
        return self.datas[0].x <= other.datas[0].x

    def __ge__(self, other):
        return self.datas[0].x >= other.datas[0].x

    def __str__(self):
        return str(self.datas)

def main():
    N = nextInt()
    L = nextInt()
    s = Datas([Data(nextString()) for i in range(N)])

    out(N, L, s)
    s.sort()
    out(s)

    ans = ""
    for i in range(N):
        ans += s[i].x
    print(ans)

if __name__ == "__main__":
    main()

