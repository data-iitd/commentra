import heapq

# Class representing a Job with two attributes 'a' and 'b'
class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    # Override compareTo method to define the ordering of Jobs
    def __lt__(self, other):
        # Compare based on 'a' first, and if equal, then by 'b'
        if other.a == self.a:
            return self.b - other.b
        else:
            return self.a - other.a

def main():
    # Create a Scanner object to read input
    sc = Scanner(System.in)

    # Read the first line of input and split it to get N and M
    line = sc.nextLine().split(" \u2581 ")
    N = int(line[0])  # Number of jobs
    M = int(line[1])  # Maximum time or limit

    # Create a priority queue to hold the jobs
    q = []

    # Read the job details and add them to the priority queue
    for i in range(N):
        line = sc.nextLine().split(" \u2581 ")
        heapq.heappush(q, Job(int(line[0]), int(line[1])))

    cnt = 0  # Counter to accumulate the total value of jobs processed
    jobQ = []  # Queue to hold job values in descending order

    # Process jobs for each time unit from 1 to M
    for i in range(1, M + 1):
        # While there are jobs that can be processed at time i
        while len(q) > 0:
            job = heapq.heappop(q)  # Peek at the job with the highest priority
            if job.a <= i:  # If the job can be processed at time i
                heapq.heappush(jobQ, job.b)  # Remove the job from the queue and add its value to jobQ
            else:
                break  # Break if the job cannot be processed yet
        # If there are jobs available to process, add the highest value job to the counter
        if len(jobQ) > 0:
            cnt += heapq.heappop(jobQ)  # Poll the highest value job from jobQ and add to cnt

    # Output the total value of jobs processed
    print(cnt)

if __name__ == '__main__':
    main()

