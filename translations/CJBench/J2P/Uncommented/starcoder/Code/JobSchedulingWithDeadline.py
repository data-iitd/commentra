import sys
import heapq

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
            for i in range(min(job.deadline, maxDeadline) - 1, job.arrivalTime - 1, -1):
                if timeSlots[i] == -1:
                    timeSlots[i] = job.jobId
                    count += 1
                    maxProfit += job.profit
                    break
    return [count, maxProfit]

if __name__ == "__main__":
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    jobs = []
    for i in range(1, n * 4, 4):
        jobs.append(Job(data[i], data[i + 1], data[i + 2], data[i + 3]))
    print(*jobSequencingWithDeadlines(jobs))

