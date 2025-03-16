class Job:
    def __init__(self, jobId, arrivalTime, deadline, profit):
        self.jobId = jobId
        self.arrivalTime = arrivalTime
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs):
    jobs.sort(key=lambda job: -job.profit)  # Sort jobs by profit in descending order
    max_deadline = max(job.deadline for job in jobs)  # Find the maximum deadline
    time_slots = [-1] * max_deadline  # Initialize time slots array with -1
    count = 0  # To count the number of jobs scheduled
    max_profit = 0  # To calculate the maximum profit
    for job in jobs:
        if job.arrivalTime <= job.deadline:  # Check if the job can be scheduled
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrivalTime - 2, -1):
                if time_slots[i] == -1:  # Find a time slot available for the job
                    time_slots[i] = job.jobId
                    count += 1
                    max_profit += job.profit
                    break
    return [count, max_profit]  # Return the result

def main():
    n = int(input().strip())  # Read the number of jobs
    jobs = []
    for _ in range(n):
        input_data = input().split()  # Read each job's details
        jobId = int(input_data[0])
        arrivalTime = int(input_data[1])
        deadline = int(input_data[2])
        profit = int(input_data[3])
        jobs.append(Job(jobId, arrivalTime, deadline, profit))
    result = job_sequencing_with_deadlines(jobs)  # Process the jobs
    print(result[0])  # Print the count of scheduled jobs
    print(result[1])  # Print the maximum profit

if __name__ == "__main__":
    main()
