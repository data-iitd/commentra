MAX = 100005
N = 100

class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

queue = [None] * (MAX + 1)
head = 0
tail = 0

def Enqueue(x):
    global tail
    if tail == MAX:
        tail = 0
    queue[tail] = x
    tail += 1

def Dequeue():
    global head
    if head == MAX:
        head = 0
    process = queue[head]
    head += 1
    return process

n, q = map(int, input().split())
processes = []

for _ in range(n):
    name, t = input().split()
    t = int(t)
    process = Process(name, t)
    Enqueue(process)

total_time = 0

while n > 0:
    process = Dequeue()
    if process.t > q:
        process.t -= q
        total_time += q
        Enqueue(process)
    else:
        total_time += process.t
        print(process.name, total_time)
        n -= 1

print("<END-OF-CODE>")