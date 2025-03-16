import sys
import heapq

# Initialize variables for output and input
output = sys.stdout
print = output.write

# Read the number of test cases
t = int(input().strip())

# Initialize priority queues for max and min values
pqmax = []
pqmin = []

# Initialize variables to keep track of sums and the minimum value
sumMin = 0
sumMax = 0
sumb = 0
min_val = 0

# Process each test case
for _ in range(t):
    # Read the input for the current test case
    s = input().strip().split()
    
    # If the command is '2', calculate and print the result
    if s[0][0] == '2':
        ans = min_val
        ans *= len(pqmin)
        ans -= sumMin
        ans1 = min_val
        ans1 *= len(pqmax)
        ans1 = sumMax - ans1
        print(f"{min_val} {ans + ans1 + sumb}\n")
    # If the command is '1', add the new value to the appropriate priority queue
    else:
        in_val = int(s[1])
        sumb += int(s[2])
        
        if in_val > min_val:
            heapq.heappush(pqmax, in_val)
            sumMax += in_val
        else:
            heapq.heappush(pqmin, -in_val)
            sumMin += in_val
        
        # Balance the priority queues
        if len(pqmin) > len(pqmax):
            heapq.heappush(pqmax, -heapq.heappop(pqmin))
            sumMax += heapq.heappop(pqmin)
            sumMin -= heapq.heappop(pqmin)
        
        if len(pqmax) > len(pqmin):
            heapq.heappush(pqmin, -heapq.heappop(pqmax))
            sumMin += heapq.heappop(pqmax)
            sumMax -= heapq.heappop(pqmax)
        
        # Update the minimum value
        min_val = -pqmin[0]

# Close the output to flush the output
output.close()
