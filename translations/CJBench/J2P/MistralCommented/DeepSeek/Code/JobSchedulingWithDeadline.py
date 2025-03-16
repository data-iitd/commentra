class Job:
    def __init__(self, jobId, arrivalTime, deadline, profit):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs):
    jobs.sort(key=lambda job: -job.profit)

    max_deadline = max(job.deadline for job in jobs)

    time_slots = [-1] * max_deadline

    count = 0
    max_profit = 0

    for job in jobs:
        if job.arrivalTime <= job.deadline:
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrivalTime - 2, -1):
                if time_slots[i] == -1:
                    time_slots[i] = job.jobId
                    count += 1
                    max_profit += job.profit
                    break

    return [count, max_profit]

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    jobs = []

    idx = 1
    for _ in range(n):
        jobId = int(data[idx])
        arrivalTime = int(data[idx + 1])
        deadline = int(data[idx + 2])
        profit = int(data[idx + 3])
        jobs.append(Job(jobId, arrivalTime, deadline, profit))
        idx += 4

    result = job_sequencing_with_deadlines(jobs)

    print(result[0])
    print(result[1])

if __name__ == "__main__":
    main()
