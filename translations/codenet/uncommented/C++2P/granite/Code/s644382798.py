
import sys

class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

def enqueue(Q, x):
    Q.append(x)

def dequeue(Q):
    return Q.pop(0)

def min(a, b):
    return a if a < b else b

def main():
    elaps = 0
    c = 0
    i = 0
    q = 0
    u = None
    Q = []
    n = int(input())
    q = int(input())

    for i in range(1, n + 1):
        name = input()
        t = int(input())
        enqueue(Q, Process(name, t))

    head = 0
    tail = n

    while head < tail:
        u = dequeue(Q)
        c = min(q, u.t)
        u.t -= c
        elaps += c
        if u.t > 0:
            enqueue(Q, u)
        else:
            print(u.name, elaps)

    return 0

if __name__ == "__main__":
    sys.exit(main())

