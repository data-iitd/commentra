class P:
    def __init__(self, name, t):
        self.name = name
        self.t = t

class Queue:
    def __init__(self, size):
        self.size = size
        self.queue = []
        self.head = 0
        self.tail = 0

    def enqueue(self, x):
        if len(self.queue) < self.size:
            self.queue.append(x)
            self.tail += 1

    def dequeue(self):
        if self.head < self.tail:
            x = self.queue[self.head]
            self.head += 1
            return x
        return None

def min(a, b):
    return a if a < b else b

def main():
    elaps = 0
    n, q = map(int, input().split())
    Q = Queue(n)

    for _ in range(n):
        name = input().strip()
        t = int(input().strip())
        Q.enqueue(P(name, t))

    while Q.head < Q.tail:
        u = Q.dequeue()
        c = min(q, u.t)
        u.t -= c
        elaps += c
        if u.t > 0:
            Q.enqueue(u)
        else:
            print(f"{u.name} {elaps}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
