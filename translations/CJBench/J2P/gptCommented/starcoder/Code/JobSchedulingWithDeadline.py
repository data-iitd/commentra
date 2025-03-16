import sys

# Job class to represent a job with its attributes
class Job:
    def __init__(self, jobId, arrivalTime, deadline, profit):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit

def jobSequencingWithDeadlines(jobs):
    # Sort jobs in descending order of profit
    jobs.sort(key = lambda job: -job.profit)
    
    # Find the maximum deadline to determine the size of the time slots
    maxDeadline = max(job.deadline for job in jobs)
    timeSlots = [-1] * maxDeadline # Array to keep track of time slots
    
    count = 0 # Count of jobs completed
    maxProfit = 0 # Total profit from completed jobs
    
    # Iterate through each job to schedule it
    for job in jobs:
        # Check if the job can be scheduled within its deadline
        if job.arrivalTime <= job.deadline:
            # Try to find a free time slot for the job
            for i in range(min(job.deadline - 1, maxDeadline - 1), job.arrivalTime - 1, -1):
                # If the time slot is free, schedule the job
                if timeSlots[i] == -1:
                    timeSlots[i] = job.jobId # Assign job ID to the time slot
                    count += 1 # Increment the count of completed jobs
                    maxProfit += job.profit # Add the profit of the job
                    break # Exit the loop after scheduling the job
    # Return the count of jobs completed and the total profit
    return [count, maxProfit]

# Main function to read input and call jobSequencingWithDeadlines()
if __name__ == '__main__':
    # Read the number of jobs
    n = int(input().strip())
    jobs = [] # Array to hold the jobs

    # Read job details from input
    for i in range(n):
        input = input().split()
        jobId = int(input[0])        # Job ID
        arrivalTime = int(input[1])  # Arrival time
        deadline = int(input[2])     # Deadline
        profit = int(input[3])       # Profit
        jobs.append(Job(jobId, arrivalTime, deadline, profit)) # Create and store job

    # Call the job sequencing function and get the result
    result = jobSequencingWithDeadlines(jobs)
    
    # Output the number of jobs done and the total profit
    print(result[0]) # Number of jobs completed
    print(result[1]) # Total profit earned

