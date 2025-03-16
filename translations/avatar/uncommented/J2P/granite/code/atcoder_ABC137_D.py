
import heapq

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

def compare_jobs(job1, job2):
    if job1.a == job2.a:
        return job1.b - job2.b
    else:
        return job1.a - job2.a

def main():
    line = input().split(" ")
    N = int(line[0])
    M = int(line[1])
    jobs = []
    for i in range(N):
        line = input().split(" ")
        jobs.append(Job(int(line[0]), int(line[1])))
    jobs.sort(key=cmp_to_key(compare_jobs))
    job_queue = []
    cnt = 0
    for i in range(1, M + 1):
        while jobs and jobs[0].a <= i:
            heapq.heappush(job_queue, -jobs[0].b)
            jobs.pop(0)
        if job_queue:
            cnt += -heapq.heappop(job_queue)
    print(cnt)

if __name__ == "__main__":
    main()

