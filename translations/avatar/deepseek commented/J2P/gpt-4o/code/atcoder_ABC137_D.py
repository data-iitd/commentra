import heapq

# Step 2: Define Job class
class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    # Step 2: Implement comparison method to compare jobs based on parameters a and b
    def __lt__(self, other):
        if self.a == other.a:
            return self.b > other.b  # Max heap for b
        return self.a < other.a  # Min heap for a

def main():
    # Step 4: Read input and initialize variables
    line = input().split(" \u2581 ")
    N = int(line[0])
    M = int(line[1])
    
    # Step 5: Create a priority queue to store jobs
    q = []
    
    # Step 6: Read job details and add to the priority queue
    for _ in range(N):
        line = input().split(" \u2581 ")
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
