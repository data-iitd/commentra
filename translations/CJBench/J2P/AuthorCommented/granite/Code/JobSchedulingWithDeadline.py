
import sys
from typing import List

class Job:
    def __init__(self, jobId: int, arrivalTime: int, deadline: int, profit: int):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs: List[Job]) -> List[int]:
    jobs.sort(key=lambda job: -job.profit)

    max_deadline = max(job.deadline for job in jobs)
    time_slots = [-1] * max_deadline

    count = 0
    max_profit = 0

    for job in jobs:
        if job.arrivalTime <= job.deadline:
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrivalTime - 1, -1):
                if time_slots[i] == -1:
                    time_slots[i] = job.jobId
                    count += 1
                    max_profit += job.profit
                    break

    return [count, max_profit]

if __name__ == "__main__":
    n = int(input())
    jobs = []
    for _ in range(n):
        job_id, arrival_time, deadline, profit = map(int, input().split())
        job = Job(job_id, arrival_time, deadline, profit)
        jobs.append(job)

    result = job_sequencing_with_deadlines(jobs)
    print(result[0])
    print(result[1])

