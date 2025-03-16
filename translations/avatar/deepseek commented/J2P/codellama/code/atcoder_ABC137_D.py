import sys
import heapq

# Step 2: Define Job class
class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    # Step 2: Implement compareTo method to compare jobs based on parameters a and b
    def __lt__(self, otherJob):
        if otherJob.a == self.a:
            return self.b < otherJob.b
        else:
            return self.a < otherJob.a

# Step 4: Read input and initialize variables
N, M = map(int, sys.stdin.readline().split())

# Step 5: Create a priority queue to store jobs
q = []

# Step 6: Read job details and add to the priority queue
for i in range(N):
    a, b = map(int, sys.stdin.readline().split())
    heapq.heappush(q, Job(a, b))

# Step 7: Initialize counters and another priority queue
cnt = 0
jobQ = []

# Step 8: Process each day from 1 to M
for i in range(1, M + 1):
    while q:
        job = q[0]
        if job.a <= i:
            heapq.heappush(jobQ, -job.b)
            heapq.heappop(q)
        else:
            break
    if jobQ:
        cnt += -heapq.heappop(jobQ)

# Step 10: Print the total reward
print(cnt)

