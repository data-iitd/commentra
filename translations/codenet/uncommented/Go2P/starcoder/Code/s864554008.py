# <START-OF-CODE>

class data:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.nImg = []
        self.mImg = []

    def load(self, cnt):
        ret = []
        for i in range(cnt):
            ret.append(input())

        return ret

    def exist(self):
        for i in range(self.n-self.m+1):
            for j in range(self.n-self.m+1):
                if self.match(i, j):
                    return True

        return False

    def match(self, x, y):
        for i in range(self.m):
            for j in range(self.m):
                if self.nImg[x+i][y+j]!= self.mImg[i][j]:
                    return False

        return True

def main():
    d = data()
    d.n, d.m = map(int, input().split())
    d.nImg = d.load(d.n)
    d.mImg = d.load(d.m)

    if d.exist():
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# 