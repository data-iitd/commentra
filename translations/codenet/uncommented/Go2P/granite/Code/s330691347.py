
import sys

def out(*x):
    #    print(x)
    pass

def nextInt():
    return int(input())

def nextString():
    return input()

class Data:
    def __init__(self, x):
        self.x = x

class Datas(list):
    def __init__(self, N):
        super().__init__()
        for i in range(N):
            self.append(Data(nextString()))

    def __str__(self):
        return str(self.__dict__)

N = nextInt()
L = nextInt()
s = Datas(N)

out(N, L, s)
s.sort(key=lambda x: x.x)
out(s)

ans = ''.join([x.x for x in s])
print(ans)

