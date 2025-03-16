class Data:
    def __init__(self, n, m, nImg, mImg):
        self.n = n
        self.m = m
        self.nImg = nImg
        self.mImg = mImg

    def exist(self):
        for i in range(self.n - self.m + 1):
            for j in range(self.n - self.m + 1):
                if self.match(i, j):
                    return True
        return False

    def match(self, x, y):
        for i in range(self.m):
            for j in range(self.m):
                if self.nImg[x + i][y + j] != self.mImg[i][j]:
                    return False
        return True

def load(cnt):
    ret = []
    for _ in range(cnt):
        s = input()
        ret.append(s)
    return ret

def main():
    n, m = map(int, input().split())
    nImg = load(n)
    mImg = load(m)
    d = Data(n, m, nImg, mImg)
    if d.exist():
        print("Yes")
    else:
        print("No")

main()
