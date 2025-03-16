import heapq

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
    import sys
    input = sys.stdin.readline
    line = input().strip().split(' ')
    N = int(line[0])
    M = int(line[1])
    q = []
    for _ in range(N):
        line = input().strip().split(' ')
        heapq.heappush(q, Job(int(line[0]), int(line[1])))
    
    cnt = 0
    jobQ = []
    for i in range(1, M + 1):
        while q and q[0].a <= i:
            job = heapq.heappop(q)
            heapq.heappush(jobQ, -job.b)
        if jobQ:
            cnt += -heapq.heappop(jobQ)
    
    print(cnt)

if __name__ == "__main__":
    main()
