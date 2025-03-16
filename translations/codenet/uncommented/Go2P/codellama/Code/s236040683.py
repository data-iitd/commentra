
import sys

def out(x):
    print(x)

def getInt():
    return int(sys.stdin.readline())

def getString():
    return sys.stdin.readline().strip()

class Node:
    def __init__(self):
        self.to = []

def main():
    N, M = getInt(), getInt()
    n = [Node() for i in range(N)]
    for i in range(M):
        from, to = getInt()-1, getInt()-1
        n[from].to.append(to)
        n[to].to.append(from)

    for i in range(N):
        out(len(n[i].to))

if __name__ == "__main__":
    main()

