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
    input = sys.stdin.read
    data = input().splitlines()
    line = data[0].split("▁")
    N = int(line[0])
    M = int(line[1])
    
    q = []
    for i in range(1, N + 1):
        line = data[i].split("▁")
        heapq.heappush(q, Job(int(line[0]), int(line[1])))

    cnt = 0
    jobQ = []
    
    for i in range(1, M + 1):
        while q and q[0].a <= i:
            job = heapq.heappop(q)
            heapq.heappush(jobQ, -job.b)  # Use negative to simulate max-heap
        
        if jobQ:
            cnt += -heapq.heappop(jobQ)  # Pop the largest job

    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
