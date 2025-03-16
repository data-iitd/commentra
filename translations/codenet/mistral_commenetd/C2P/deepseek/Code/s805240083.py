MAX = 100005
N = 100

class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

Q = [None] * (MAX + 1)
head = 0
tail = 0

def Enqueue(x):
    global tail
    if tail == MAX:
        tail = 0
    Q[tail] = x
    tail += 1

def Dequeue():
    global head
    if head == MAX:
        head = 0
    temp = Q[head]
    head += 1
    return temp

if __name__ == "__main__":
    n, q = map(int, input().split())
    for i in range(n):
        name, t = input().split()
        Enqueue(Process(name, int(t)))

    while n != 0:
        a = Dequeue()
        if a.t > q:
            a.t -= q
            T += q
            Enqueue(a)
        else:
            T += a.t
            print(a.name, T)
            n -= 1

