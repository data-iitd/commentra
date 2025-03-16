import heapq

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, other):
        if self.a == other.a:
            return self.b < other.b
        else:
            return self.a < other.a

# Read input
N, M = map(int, input().split('\u2581'))

# Create a list of Job objects
jobs = []
for _ in range(N):
    a, b = map(int, input().split('\u2581'))
    jobs.append(Job(a, b))

# Sort the jobs based on the Job class's __lt__ method
jobs.sort()

# Initialize variables
cnt = 0
job_heap = []

# Iterate through the number of machines
for i in range(1, M + 1):
    # While there are jobs available and the next job can be started on the current machine
    while jobs and jobs[0].a <= i:
        # Push the job's benefit onto the heap
        heapq.heappush(job_heap, -jobs.pop(0).b)
    
    # If the heap is not empty, add the highest benefit job to the counter
    if job_heap:
        cnt += -heapq.heappop(job_heap)

# Print the result
print(cnt)
