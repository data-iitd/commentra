
import heapq

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

def main():
    sc = Scanner(System.in)

    line = sc.nextLine().split("\u2581")
    N = int(line[0])
    M = int(line[1])

    q = []
    for i in range(N):
        line = sc.nextLine().split("\u2581")
        heapq.heappush(q, (int(line[0]), int(line[1])))

    cnt = 0
    jobQ = []
    for i in range(1, M + 1):
        while q:
            job = q[0]
            if job[0] <= i:
                heapq.heappush(jobQ, job[1])
                heapq.heappop(q)
            else:
                break

        if jobQ:
            cnt += heapq.heappop(jobQ)

    print(cnt)

if __name__ == "__main__":
    main()

