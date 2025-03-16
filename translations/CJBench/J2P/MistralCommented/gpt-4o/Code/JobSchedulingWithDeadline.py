class Job:
    def __init__(self, job_id, arrival_time, deadline, profit):
        self.job_id = job_id
        self.arrival_time = arrival_time
        self.deadline = deadline
        self.profit = profit

def job_sequencing_with_deadlines(jobs):
    # Sort the jobs in descending order of profit
    jobs.sort(key=lambda job: -job.profit)

    # Find the maximum deadline among all jobs
    max_deadline = max(job.deadline for job in jobs)

    # Create a list to store the job_id that can be scheduled in each time slot
    time_slots = [-1] * max_deadline

    count = 0  # Counter for the number of jobs processed
    max_profit = 0  # Variable to keep track of the maximum profit earned

    for job in jobs:
        if job.arrival_time <= job.deadline:  # Check if the job can be processed before its deadline
            for i in range(min(job.deadline - 1, max_deadline - 1), job.arrival_time - 2, -1):
                if time_slots[i] == -1:  # Check if the time slot is empty
                    time_slots[i] = job.job_id  # Assign the job_id to the empty time slot
                    count += 1  # Increment the counter
                    max_profit += job.profit  # Add the profit of the job to the maximum profit
                    break  # Exit the loop as soon as a suitable time slot is found

    return count, max_profit  # Return the number of jobs processed and the maximum profit earned

if __name__ == "__main__":
    n = int(input().strip())  # Read number of jobs from input

    jobs = []  # Create a list to store Job objects

    for _ in range(n):  # Iterate through each line of input and create a new Job object
        job_id, arrival_time, deadline, profit = map(int, input().split())
        jobs.append(Job(job_id, arrival_time, deadline, profit))  # Append the new Job object to the jobs list

    result = job_sequencing_with_deadlines(jobs)  # Call the job_sequencing_with_deadlines function to get the result

    print(result[0])  # Print the number of jobs processed
    print(result[1])  # Print the maximum profit earned

# <END-OF-CODE>
