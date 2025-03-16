
import sys
from operator import itemgetter

def job_sequencing_with_deadlines(jobs):
    jobs.sort(key=itemgetter(3), reverse=True) # Sort jobs by profit in descending order
    max_deadline = max(jobs, key=itemgetter(2))[2] # Find the maximum deadline
    time_slots = [-1] * max_deadline # Initialize time slots array with -1
    count = 0 # To count the number of jobs scheduled
    max_profit = 0 # To calculate the maximum profit
    for job in jobs:
        if job[1] <= job[2]: # Check if the job can be scheduled
            for i in range(min(job[2] - 1, max_deadline - 1), job[1] - 1, -1):
                if time_slots[i] == -1: # Find a time slot available for the job
                    time_slots[i] = job[0]
                    count += 1
                    max_profit += job[3]
                    break
    return [count, max_profit] # Return the result

if __name__ == "__main__":
    n = int(input()) # Read the number of jobs
    jobs = []
    for _ in range(n):
        job_id, arrival_time, deadline, profit = map(int, input().split())
        jobs.append([job_id, arrival_time, deadline, profit])
    result = job_sequencing_with_deadlines(jobs) # Process the jobs
    print(result[0]) # Print the count of scheduled jobs
    print(result[1]) # Print the maximum profit

