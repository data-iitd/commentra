import sys
import heapq

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, other):
        if self.a == other.a:
            return self.b < other.b
        return self.a < other.a

def main():
    N, M = map(int, sys.stdin.readline().split())
    q = []
    for i in range(N):
        a, b = map(int, sys.stdin.readline().split())
        heapq.heappush(q, Job(a, b))
    cnt = 0
    jobQ = []
    for i in range(1, M + 1):
        while q:
            job = heapq.heappop(q)
            if job.a <= i:
                heapq.heappush(jobQ, job.b)
            else:
                break
        if jobQ:
            cnt += heapq.heappop(jobQ)
    print(cnt)

if __name__ == "__main__":
    main()

