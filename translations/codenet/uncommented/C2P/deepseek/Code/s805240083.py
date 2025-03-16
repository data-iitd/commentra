MAX = 100005
N = 100

class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

Q = [None] * MAX
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
    x = Q[head]
    head += 1
    return x

n, q = map(int, input().split())

for _ in range(n):
    name, t = input().split()
    t = int(t)
    Enqueue(Process(name, t))

T = 0
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

