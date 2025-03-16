class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

def enqueue(queue, process, tail):
    queue[tail] = process
    return (tail + 1) % len(queue)

def dequeue(queue, head):
    process = queue[head]
    return process, (head + 1) % len(queue)

def min(a, b):
    return a if a < b else b

def main():
    elaps = 0
    c = 0
    n, q = map(int, input().split())
    queue = [None] * (n + 1)
    processes = []

    for i in range(1, n + 1):
        name, t = input().split()
        t = int(t)
        processes.append(Process(name, t))
        queue[i] = processes[-1]

    head = 1
    tail = n + 1

    while head != tail:
        u, head = dequeue(queue, head)
        c = min(q, u.t)
        u.t -= c
        elaps += c
        if u.t > 0:
            tail = enqueue(queue, u, tail)
        else:
            print(f"{u.name} {elaps}")

if __name__ == "__main__":
    main()
