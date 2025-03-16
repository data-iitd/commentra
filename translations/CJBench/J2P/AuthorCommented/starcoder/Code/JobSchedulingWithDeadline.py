import sys

# Represents a job with an ID, arrival time, deadline, and profit.
#
# Each job has a unique identifier, an arrival time (when it becomes available for scheduling),
# a deadline by which it must be completed, and a profit associated with completing the job.
class Job:
    def __init__(self, jobId, arrivalTime, deadline, profit):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit


# Main method to take input from the user, perform job scheduling, and print output.
def main():
    # Read number of jobs
    n = int(input().strip())

    jobs = []

    # Read job details without prompting
    for i in range(n):
        input = input().split()
        jobId = int(input[0])
        arrivalTime = int(input[1])
        deadline = int(input[2])
        profit = int(input[3])
        jobs.append(Job(jobId, arrivalTime, deadline, profit))

    # Call the job scheduling function
    result = jobSequencingWithDeadlines(jobs)

    # Print the results
    print(result[0])
    print(result[1])


# Schedules jobs to maximize profit while respecting their deadlines and arrival times.
#
# This method sorts the jobs in descending order of profit and attempts
# to allocate them to time slots that are before or on their deadlines,
# provided they have arrived. The function returns an array where the first element
# is the total number of jobs scheduled and the second element is the total profit earned.
def jobSequencingWithDeadlines(jobs):
    jobs.sort(key=lambda job: -job.profit)

    maxDeadline = max(job.deadline for job in jobs)
    timeSlots = [-1] * maxDeadline

    count = 0
    maxProfit = 0

    # Schedule the jobs
    for job in jobs:
        if job.arrivalTime <= job.deadline:
            for i in range(min(job.deadline - 1, maxDeadline - 1), job.arrivalTime - 1, -1):
                if timeSlots[i] == -1:
                    timeSlots[i] = job.jobId
                    count += 1
                    maxProfit += job.profit
                    break

    return [count, maxProfit]


if __name__ == "__main__":
    main()

# 