class Job:
    def __init__(self, job_id, arrival_time, deadline, profit):
        self.job_id = job_id
        self.arrival_time = arrival_time
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs):
    jobs.sort(key=lambda job: -job.profit)
    max_deadline = max(job.deadline for job in jobs)
    time_slots = [-1] * max_deadline
    count = 0
    max_profit = 0
    for job in jobs:
        if job.arrival_time <= job.deadline:
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrival_time - 2, -1):
                if time_slots[i] == -1:
                    time_slots[i] = job.job_id
                    count += 1
                    max_profit += job.profit
                    break
    return [count, max_profit]

def main():
    n = int(input().strip())
    jobs = []
    for _ in range(n):
        job_id, arrival_time, deadline, profit = map(int, input().split())
        jobs.append(Job(job_id, arrival_time, deadline, profit))
    result = job_sequencing_with_deadlines(jobs)
    print(result[0])
    print(result[1])

if __name__ == "__main__":
    main()
