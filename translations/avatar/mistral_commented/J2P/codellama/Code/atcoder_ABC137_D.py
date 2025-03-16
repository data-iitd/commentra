import queue

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, other):
        if self.a == other.a:
            return self.b < other.b
        else:
            return self.a < other.a


def main():
    N, M = map(int, input().split())
    q = queue.PriorityQueue()

    for _ in range(N):
        a, b = map(int, input().split())
        q.put(Job(a, b))

    cnt = 0
    jobQ = queue.PriorityQueue()

    for i in range(1, M + 1):
        while not q.empty():
            job = q.get()
            if job.a <= i:
                jobQ.put(job.b)
            else:
                break

        if not jobQ.empty():
            cnt += jobQ.get()

    print(cnt)


if __name__ == "__main__":
    main()


