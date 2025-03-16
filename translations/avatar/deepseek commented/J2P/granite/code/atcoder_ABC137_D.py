
import heapq

# Step 2: Define Job class
class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Step 3: Implement compareTo method to compare jobs based on parameters a and b
def compare_jobs(job1, job2):
    if job1.a == job2.a:
        return job1.b - job2.b
    else:
        return job1.a - job2.a

# Step 4: Read input and initialize variables
line = input().split(" ")
N = int(line[0])
M = int(line[1])

# Step 5: Create a priority queue to store jobs
q = []

# Step 6: Read job details and add to the priority queue
for i in range(N):
    line = input().split(" ")
    heapq.heappush(q, Job(int(line[0]), int(line[1])))

# Step 7: Initialize counters and another priority queue
cnt = 0
jobQ = []

# Step 8: Process each day from 1 to M
for i in range(1, M + 1):
    while q and q[0].a <= i:
        job = heapq.heappop(q)
        heapq.heappush(jobQ, job.b)
    if jobQ:
        cnt += heapq.heappop(jobQ)

# Step 10: Print the total reward
print(cnt)

