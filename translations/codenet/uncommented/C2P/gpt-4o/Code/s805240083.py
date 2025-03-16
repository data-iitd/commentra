MAX = 100005
N = 100

class P:
    def __init__(self, name, t):
        self.name = name
        self.t = t

Q = [None] * (MAX + 1)
head = 0
tail = 0

def enqueue(x):
    global tail
    if tail == MAX:
        tail = 0
    Q[tail] = x
    tail += 1

def dequeue():
    global head
    if head == MAX:
        head = 0
    result = Q[head]
    head += 1
    return result

def main():
    global head, tail
    T = 0
    n, q = map(int, input().split())

    for _ in range(n):
        name, t = input().split()
        t = int(t)
        a = P(name, t)
        enqueue(a)

    while n != 0:
        a = dequeue()
        if a.t > q:
            a.t -= q
            T += q
            enqueue(a)
        else:
            T += a.t
            print(f"{a.name} {T}")
            n -= 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
