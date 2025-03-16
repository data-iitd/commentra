import heapq

class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, other):
        if other.a == self.a:
            return self.b > other.b
        else:
            return self.a < other.a

# Read input
N, M = map(int, input().split(' \u2581 '))

# Create a list to store jobs
jobs = []
for _ in range(N):
    a, b = map(int, input().split(' \u2581 '))
    jobs.append(Job(a, b))

# Sort jobs based on the custom comparator
jobs.sort()

# Initialize counters and a max heap
cnt = 0
max_heap = []

# Process each day from 1 to M
for day in range(1, M + 1):
    # Add eligible jobs to the max heap
    while jobs and jobs[-1].a <= day:
        job = jobs.pop()
        heapq.heappush(max_heap, -job.b)
    
    # Process the job with the maximum reward today
    if max_heap:
        cnt += -heapq.heappop(max_heap)

# Print the total reward
print(cnt)
