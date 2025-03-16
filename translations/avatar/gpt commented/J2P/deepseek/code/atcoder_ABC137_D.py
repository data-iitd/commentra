import heapq
import sys

# Class representing a Job with two attributes 'a' and 'b'
class Job:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, other):
        if self.a == other.a:
            return self.b < other.b
        else:
            return self.a < other.a

# Main function
def main():
    # Read the first line of input and split it to get N and M
    line = input().split(" \u2581 ")
    N = int(line[0])  # Number of jobs
    M = int(line[1])  # Maximum time or limit

    # Create a list to hold the jobs
    jobs = []

    # Read the job details and add them to the list
    for _ in range(N):
        line = input().split(" \u2581 ")
        jobs.append(Job(int(line[0]), int(line[1])))

    # Sort the jobs based on their 'a' attribute
    jobs.sort()

    cnt = 0  # Counter to accumulate the total value of jobs processed
    jobQ = []  # List to hold job values in descending order

    # Process jobs for each time unit from 1 to M
    for i in range(1, M + 1):
        # While there are jobs that can be processed at time i
        while jobs and jobs[0].a <= i:
            job = jobs.pop(0)  # Remove the job from the list
            heapq.heappush(jobQ, -job.b)  # Add its value to jobQ with negative sign for max heap

        # If there are jobs available to process, add the highest value job to the counter
        if jobQ:
            cnt += -heapq.heappop(jobQ)  # Pop the highest value job from jobQ and add to cnt

    # Output the total value of jobs processed
    print(cnt)

if __name__ == "__main__":
    main()
