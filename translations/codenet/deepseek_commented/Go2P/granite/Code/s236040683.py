

import sys

def out(*args):
    print(*args)

def getInt():
    return int(input())

def getString():
    return input()

class Node:
    def __init__(self):
        self.to = []

if __name__ == '__main__':
    sc = bufio.Scanner(sys.stdin)
    sc.use_dict = True

    N, M = getInt(), getInt()
    n = [Node() for _ in range(N)]

    for _ in range(M):
        from_, to = getInt()-1, getInt()-1
        n[from_].to.append(to)
        n[to].to.append(from_)

    for i in range(N):
        out(len(n[i].to))

