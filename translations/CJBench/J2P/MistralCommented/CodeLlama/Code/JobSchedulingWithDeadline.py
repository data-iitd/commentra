
import sys

class Job:
    def __init__(self, jobId, arrivalTime, deadline, profit):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit

def jobSequencingWithDeadlines(jobs):
    jobs.sort(key=lambda job: -job.profit)

    maxDeadline = max(job.deadline for job in jobs)

    timeSlots = [-1] * maxDeadline

    count = 0
    maxProfit = 0

    for job in jobs:
        if job.arrivalTime <= job.deadline:
            for i in range(max(job.deadline - 1, maxDeadline - 1), job.arrivalTime - 1, -1):
                if timeSlots[i] == -1:
                    timeSlots[i] = job.jobId
                    count += 1
                    maxProfit += job.profit
                    break

    return [count, maxProfit]

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())

    jobs = []

    for _ in range(n):
        jobId, arrivalTime, deadline, profit = map(int, sys.stdin.readline().strip().split())
        jobs.append(Job(jobId, arrivalTime, deadline, profit))

    result = jobSequencingWithDeadlines(jobs)

    print(result[0])
    print(result[1])

