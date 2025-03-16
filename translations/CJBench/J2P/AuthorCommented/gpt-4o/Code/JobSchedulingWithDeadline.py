import sys

class Job:
    def __init__(self, job_id, arrival_time, deadline, profit):
        self.job_id = job_id
        self.arrival_time = arrival_time
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs):
    # Sort jobs in descending order of profit
    jobs.sort(key=lambda job: -job.profit)

    max_deadline = max(job.deadline for job in jobs)
    time_slots = [-1] * max_deadline

    count = 0
    max_profit = 0

    # Schedule the jobs
    for job in jobs:
        if job.arrival_time <= job.deadline:
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrival_time - 2, -1):
                if time_slots[i] == -1:
                    time_slots[i] = job.job_id
                    count += 1
                    max_profit += job.profit
                    break

    return count, max_profit

def main():
    # Read number of jobs
    n = int(sys.stdin.readline().strip())

    jobs = []

    # Read job details without prompting
    for _ in range(n):
        input_data = list(map(int, sys.stdin.readline().strip().split()))
        job_id = input_data[0]
        arrival_time = input_data[1]
        deadline = input_data[2]
        profit = input_data[3]
        jobs.append(Job(job_id, arrival_time, deadline, profit))

    # Call the job scheduling function
    result = job_sequencing_with_deadlines(jobs)

    # Print the results
    print(result[0])
    print(result[1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
