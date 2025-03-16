
import sys

def enqueue(x):
    global Q, tail
    Q[tail] = x
    tail = (tail + 1) % LEN

def dequeue():
    global Q, head
    x = Q[head]
    head = (head + 1) % LEN
    return x

def min(a, b):
    return a if a < b else b

def main():
    global n, q, Q, head, tail, elaps
    n, q = map(int, sys.stdin.readline().split())
    for i in range(1, n + 1):
        Q[i] = list(sys.stdin.readline().split())
        enqueue(Q[i])
    head = 1
    tail = n + 1
    while head != tail:
        u = dequeue()
        c = min(q, int(u[1]))
        u[1] = int(u[1]) - c
        elaps += c
        if int(u[1]) > 0:
            enqueue(u)
        else:
            print(' '.join(u) + ' ' + str(elaps))

if __name__ == '__main__':
    main()
    # 