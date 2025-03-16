class Data:
    def __init__(self):
        self.n, self.m = map(int, input().split())
        self.nImg = self.load(self.n)
        self.mImg = self.load(self.m)

    def load(self, cnt):
        ret = []
        for _ in range(cnt):
            ret.append(input().strip())
        return ret

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


if __name__ == "__main__":
    d = Data()
    if d.exist():
        print("Yes")
    else:
        print("No")

# <END-OF-CODE>
