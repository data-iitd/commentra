class Job:
    def __init__(self, job_id, arrival_time, deadline, profit):
        self.job_id = job_id
        self.arrival_time = arrival_time
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs):
    # Sort jobs in descending order of profit
    jobs.sort(key=lambda job: -job.profit)
    
    # Find the maximum deadline to determine the size of the time slots
    max_deadline = max(job.deadline for job in jobs) if jobs else 0
    time_slots = [-1] * max_deadline  # Initialize time slots as unoccupied (-1)
    
    count = 0  # Count of jobs completed
    max_profit = 0  # Total profit from completed jobs
    
    # Iterate through each job to schedule it
    for job in jobs:
        # Check if the job can be scheduled within its deadline
        if job.arrival_time <= job.deadline:
            # Try to find a free time slot for the job
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrival_time - 2, -1):
                # If the time slot is free, schedule the job
                if time_slots[i] == -1:
                    time_slots[i] = job.job_id  # Assign job ID to the time slot
                    count += 1  # Increment the count of completed jobs
                    max_profit += job.profit  # Add the profit of the job
                    break  # Exit the loop after scheduling the job
    
    # Return the count of jobs completed and the total profit
    return count, max_profit

if __name__ == "__main__":
    import sys
    
    # Read the number of jobs
    n = int(sys.stdin.readline().strip())
    jobs = []  # List to hold the jobs

    # Read job details from input
    for _ in range(n):
        input_data = list(map(int, sys.stdin.readline().strip().split()))
        job_id = input_data[0]        # Job ID
        arrival_time = input_data[1]   # Arrival time
        deadline = input_data[2]       # Deadline
        profit = input_data[3]         # Profit
        jobs.append(Job(job_id, arrival_time, deadline, profit))  # Create and store job

    # Call the job sequencing function and get the result
    result = job_sequencing_with_deadlines(jobs)
    
    # Output the number of jobs done and the total profit
    print(result[0])  # Number of jobs completed
    print(result[1])  # Total profit earned

# <END-OF-CODE>
