
import sys
import heapq

# Class representing a Job with two attributes 'a' and 'b'
class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    # Override compareTo method to define the ordering of Jobs
    def __lt__(self, otherJob):
        # Compare based on 'a' first, and if equal, then by 'b'
        if otherJob.a == self.a:
            return self.b < otherJob.b
        else:
            return self.a < otherJob.a

# Read the first line of input and split it to get N and M
line = sys.stdin.readline().split(" \u2581 ")
N = int(line[0]) # Number of jobs
M = int(line[1]) # Maximum time or limit

# Create a priority queue to hold the jobs
q = []

# Read the job details and add them to the priority queue
for i in range(N):
    line = sys.stdin.readline().split(" \u2581 ")
    job = Job(int(line[0]), int(line[1]))
    heapq.heappush(q, job)

cnt = 0 # Counter to accumulate the total value of jobs processed
jobQ = [] # Queue to hold job values in descending order

# Process jobs for each time unit from 1 to M
for i in range(1, M+1):
    # While there are jobs that can be processed at time i
    while len(q) > 0:
        job = q[0] # Peek at the job with the highest priority
        if job.a <= i: # If the job can be processed at time i
            jobQ.append(job.b) # Remove the job from the queue and add its value to jobQ
            heapq.heappop(q)
        else:
            break # Break if the job cannot be processed yet
    # If there are jobs available to process, add the highest value job to the counter
    if len(jobQ) > 0:
        cnt += jobQ.pop() # Poll the highest value job from jobQ and add to cnt

# Output the total value of jobs processed
print(cnt)

