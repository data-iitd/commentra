import heapq

# Class representing a Job with two attributes 'a' and 'b'
class Job:
    def __init__(self, a, b):
        self.a = a  # Represents the time or priority of the job
        self.b = b  # Represents the value or weight of the job

    # Define comparison for the priority queue
    def __lt__(self, other):
        if self.a == other.a:
            return self.b > other.b  # Higher value jobs come first if 'a' is equal
        return self.a < other.a  # Lower 'a' comes first

def main():
    # Read the first line of input and split it to get N and M
    line = input().strip().split(" \u2581 ")
    N = int(line[0])  # Number of jobs
    M = int(line[1])  # Maximum time or limit

    # Create a priority queue to hold the jobs
    job_queue = []
    
    # Read the job details and add them to the priority queue
    for _ in range(N):
        line = input().strip().split(" \u2581 ")
        heapq.heappush(job_queue, Job(int(line[0]), int(line[1])))

    cnt = 0  # Counter to accumulate the total value of jobs processed
    job_values = []  # List to hold job values in descending order

    # Process jobs for each time unit from 1 to M
    for i in range(1, M + 1):
        # While there are jobs that can be processed at time i
        while job_queue and job_queue[0].a <= i:
            job = heapq.heappop(job_queue)  # Remove the job from the queue
            heapq.heappush(job_values, -job.b)  # Add its value to job_values (negated for max-heap)

        # If there are jobs available to process, add the highest value job to the counter
        if job_values:
            cnt += -heapq.heappop(job_values)  # Poll the highest value job from job_values and add to cnt

    # Output the total value of jobs processed
    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
