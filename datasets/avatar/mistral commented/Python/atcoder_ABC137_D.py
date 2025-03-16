# Importing heapq module for implementing min heap
import heapq

# Taking input of number of days and number of employees
n, m = map(int, input().split())

# Initializing empty lists for storing days and salaries
x = []
y = []

# Iterating through each employee and adding their details to the heap 'x'
for i in range(n):
    day, salary = map(int, input().split())
    # Adding employee details as a tuple to the heap 'x' with negative day and salary values
    heapq.heappush(x, (-day, -salary))

# Simulation loop to check if an employee can be added to the list 'y'
while x:
    # Popping the employee with minimum negative day from the heap 'x'
    d, s = heapq.heappop(x)
    # Calculating the remaining capacity in the list 'y'
    r = m - len(y)
    # Checking if the remaining capacity is enough to add the current employee
    if r >= d:
        # If yes, adding the salary of the employee to the list 'y'
        heapq.heappush(y, -s)
    else:
        # If no, removing an employee with minimum salary from the list 'y' and adding the current employee
        heapq.heappush(y, -s)
        heapq.heappop(y)

# Printing the sum of salaries of employees in the list 'y'
print(sum(y))
