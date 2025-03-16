
import sys

# Represents a job with an ID, arrival time, deadline, and profit.
class Job:
    def __init__(self, job_id, arrival_time, deadline, profit):
        self.job_id = job_id
        self.arrival_time = arrival_time
        self.deadline = deadline
        self.profit = profit

# Main method to take input from the user, perform job scheduling, and print output.
def main():
    # Read number of jobs
    n = int(sys.stdin.readline().strip())

    jobs = []

    # Read job details without prompting
    for i in range(n):
        job_id, arrival_time, deadline, profit = map(int, sys.stdin.readline().strip().split())
        jobs.append(Job(job_id, arrival_time, deadline, profit))

    # Call the job scheduling function
    result = job_sequencing_with_deadlines(jobs)

    # Print the results
    print(result[0])
    print(result[1])

# Schedules jobs to maximize profit while respecting their deadlines and arrival times.
#
# This method sorts the jobs in descending order of profit and attempts
# to allocate them to time slots that are before or on their deadlines,
# provided they have arrived. The function returns an array where the first element
# is the total number of jobs scheduled and the second element is the total profit earned.
def job_sequencing_with_deadlines(jobs):
    jobs.sort(key=lambda job: -job.profit)

    max_deadline = max(job.deadline for job in jobs)
    time_slots = [-1] * max_deadline

    count = 0
    max_profit = 0

    # Schedule the jobs
    for job in jobs:
        if job.arrival_time <= job.deadline:
            for i in range(max(job.deadline - 1, max_deadline - 1), job.arrival_time - 1, -1):
                if time_slots[i] == -1:
                    time_slots[i] = job.job_id
                    count += 1
                    max_profit += job.profit
                    break

    return [count, max_profit]


if __name__ == "__main__":
    main()

