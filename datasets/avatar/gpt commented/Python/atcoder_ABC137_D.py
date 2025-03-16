import heapq

# Read the number of days (n) and the maximum number of jobs (m) from input
n, m = map(int, input().split())

# Initialize two heaps: one for jobs (x) and one for selected salaries (y)
x = []
y = []

# Read the job details for n days
for i in range(n):
    # For each day, read the day number and salary
    day, salary = map(int, input().split())
    # Push the negative of day and salary onto the heap to create a max-heap
    heapq.heappush(x, (-day, -salary))

# Process the jobs in the heap until it's empty
while x:
    # Pop the job with the highest day and salary (due to negation)
    d, s = heapq.heappop(x)
    
    # Calculate the remaining capacity for jobs
    r = m - len(y)
    
    # If there is enough capacity to take the job
    if r >= -d:
        # Add the salary to the selected salaries heap
        heapq.heappush(y, -s)
    else:
        # If capacity is full, replace the lowest salary if the new salary is higher
        heapq.heappush(y, -s)
        heapq.heappop(y)  # Remove the lowest salary from the heap

# Output the total sum of selected salaries
print(sum(y))
