LEN = 100005

class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

queue = [None] * LEN
head = 0
tail = 0

def enqueue(x):
    global tail
    queue[tail] = x
    tail = (tail + 1) % LEN

def dequeue():
    global head
    x = queue[head]
    head = (head + 1) % LEN
    return x

def min(a, b):
    return a if a < b else b

n, q = map(int, input().split())

for i in range(1, n + 1):
    name, t = input().split()
    t = int(t)
    enqueue(Process(name, t))

elaps = 0

while head != tail:
    u = dequeue()
    c = min(q, u.t)
    u.t -= c
    elaps += c
    if u.t > 0:
        enqueue(u)
    else:
        print(u.name, elaps)

# <END-OF-CODE>