class Process:
    def __init__(self, name, time):
        self.name = name
        self.time = time

LEN = 100005

Q = [None] * LEN
head = 0
tail = 0

def enqueue(x):
    global tail
    Q[tail] = x
    tail = (tail + 1) % LEN

def dequeue():
    global head
    x = Q[head]
    head = (head + 1) % LEN
    return x

def min(a, b):
    return a if a < b else b

n, q = map(int, input().split())

for i in range(n):
    name, time = input().split()
    enqueue(Process(name, int(time)))

elaps = 0

while head != tail:
    u = dequeue()
    c = min(q, u.time)
    u.time -= c
    elaps += c
    if u.time > 0:
        enqueue(u)
    else:
        print(u.name, elaps)

