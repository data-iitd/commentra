

import sys
from typing import List

class Job:
    def __init__(self, jobId: int, arrivalTime: int, deadline: int, profit: int):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs: List[Job]) -> List[int]:
    jobs.sort(key=lambda job: -job.profit) # Sort the jobs in descending order of profit

    max_deadline = max(job.deadline for job in jobs) # Find the maximum deadline among all jobs

    time_slots = [-1] * max_deadline # Create an array of size max_deadline to store the jobId that can be scheduled in each time slot

    count = 0 # Initialize a counter to keep track of the number of jobs processed
    max_profit = 0 # Initialize a variable to keep track of the maximum profit earned

    for job in jobs: # Iterate through each job
        if job.arrivalTime <= job.deadline: # Check if the job can be processed before its deadline
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrivalTime - 1, -1): # Iterate through all possible time slots before the job's deadline
                if time_slots[i] == -1: # Check if the time slot is empty
                    time_slots[i] = job.jobId # Assign the jobId to the empty time slot
                    count += 1 # Increment the counter
                    max_profit += job.profit # Add the profit of the job to the maximum profit
                    break # Exit the loop as soon as a suitable time slot is found

    return [count, max_profit] # Return an array containing the number of jobs processed and the maximum profit earned

jobs = [] # Initialize an empty list to store Job objects

for line in sys.stdin: # Iterate through each line of input
    job_id, arrival_time, deadline, profit = map(int, line.split()) # Parse the input and assign values to jobId, arrivalTime, deadline, and profit
    job = Job(job_id, arrival_time, deadline, profit) # Create a new Job object and append it to the jobs list
    jobs.append(job)

result = job_sequencing_with_deadlines(jobs) # Call the job_sequencing_with_deadlines function to get the result

print(result[0]) # Print the number of jobs processed
print(result[1]) # Print the maximum profit earned

