
import heapq

# Class representing a Job with two attributes 'a' and 'b'
class Job:
    def __init__(self, a, b):
        self.a = a  # Represents the time or priority of the job
        self.b = b  # Represents the value or weight of the job

# Override __lt__ method to define the ordering of Jobs
class JobComparator:
    def __init__(self):
        pass

    def __lt__(self, other):
        # Compare based on 'a' first, and if equal, then by 'b'
        if self.a == other.a:
            return self.b < other.b
        else:
            return self.a < other.a

# Read input and split it to get N and M
N, M = map(int, input().split())  # Number of jobs and maximum time or limit

# Create a priority queue to hold the jobs
q = []

# Read the job details and add them to the priority queue
for _ in range(N):
    a, b = map(int, input().split())
    heapq.heappush(q, Job(a, b))

# Sort the jobs in descending order based on their values
q.sort(key=lambda x: x.b, reverse=True)

cnt = 0  # Counter to accumulate the total value of jobs processed
jobQ = []  # Queue to hold job values in descending order

# Process jobs for each time unit from 1 to M
for i in range(1, M + 1):
    while q and q[0].a <= i:
        job = heapq.heappop(q)  # Remove the job with the highest priority
        heapq.heappush(jobQ, job.b)  # Add the job's value to jobQ
    if jobQ:
        cnt += heapq.heappop(jobQ)  # Poll the highest value job from jobQ and add to cnt

# Output the total value of jobs processed
print(cnt)

