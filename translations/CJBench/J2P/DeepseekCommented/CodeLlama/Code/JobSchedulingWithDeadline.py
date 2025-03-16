import sys

def jobSequencingWithDeadlines(jobs):
    jobs.sort(key=lambda x: -x.profit)
    max_deadline = max(job.deadline for job in jobs)
    time_slots = [-1] * max_deadline
    count = 0
    max_profit = 0
    for job in jobs:
        if job.arrival_time <= job.deadline:
            for i in range(max(job.deadline - 1, max_deadline - 1), job.arrival_time - 1, -1):
                if time_slots[i] == -1:
                    time_slots[i] = job.job_id
                    count += 1
                    max_profit += job.profit
                    break
    return count, max_profit

class Job:
    def __init__(self, job_id, arrival_time, deadline, profit):
        self.job_id = job_id
        self.arrival_time = arrival_time
        self.deadline = deadline
        self.profit = profit

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    jobs = []
    for _ in range(n):
        job_id, arrival_time, deadline, profit = map(int, sys.stdin.readline().strip().split())
        jobs.append(Job(job_id, arrival_time, deadline, profit))
    count, max_profit = jobSequencingWithDeadlines(jobs)
    print(count)
    print(max_profit)

