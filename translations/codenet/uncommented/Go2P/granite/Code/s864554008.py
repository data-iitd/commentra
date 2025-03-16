
class Data:
    def __init__(self):
        self.n, self.m = map(int, input().split())
        self.nImg = [input() for _ in range(self.n)]
        self.mImg = [input() for _ in range(self.m)]

    def exist(self):
        for i in range(self.n - self.m + 1):
            for j in range(self.n - self.m + 1):
                if self.match(i, j):
                    return True
        return False

    def match(self, x, y):
        for i in range(self.m):
            for j in range(self.m):
                if self.nImg[x + i][y + j]!= self.mImg[i][j]:
                    return False
        return True

d = Data()
if d.exist():
    print("Yes")
else:
    print("No")
