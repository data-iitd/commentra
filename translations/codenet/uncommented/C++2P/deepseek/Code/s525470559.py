from collections import deque

class Task:
    def __init__(self, name, time):
        self.name = name
        self.time = time

def main():
    n, q = map(int, input().split())
    Q = deque()
    elaps = 0

    for _ in range(n):
        name, time = input().split()
        time = int(time)
        Q.append(Task(name, time))

    while Q:
        p = Q.popleft()
        if p.time <= q:
            elaps += p.time
            print(p.name, elaps)
        else:
            p.time -= q
            elaps += q
            Q.append(p)

if __name__ == "__main__":
    main()
