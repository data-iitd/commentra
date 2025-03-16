
import heapq

# Read the number of jobs and the maximum number of days available
n, m = map(int, input().split())

# Initialize lists to store job days and salaries
x = []
y = []

# Read each job's day and salary, and push them into the heap x
for i in range(n):
    day, salary = map(int, input().split())
    # Push the day and salary as negative values to simulate a max-heap
    heapq.heappush(x, (-day, -salary))

# Process the jobs in the order of their deadlines
while x:
    # Pop the job with the largest deadline (negated values)
    d, s = heapq.heappop(x)
    
    # Calculate the remaining days available for new jobs
    r = m - len(y)
    
    # If there are enough days to accommodate this job
    if r >= -d:
        # Add the salary to the list of chosen salaries
        heapq.heappush(y, -s)
    else:
        # If not enough days, check if we need to remove the smallest salary
        heapq.heappush(y, -s)
        heapq.heappop(y)

# Output the sum of the chosen salaries
print(sum(y))
