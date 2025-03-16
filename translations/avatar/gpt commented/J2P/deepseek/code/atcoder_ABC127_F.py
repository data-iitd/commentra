import sys
import heapq

# Output stream for printing results
output_stream = sys.stdout
out = output_stream.write

# Read the number of test cases
t = int(input().strip())

# Priority queues for processing input
pqmax = []  # Min-heap for maximum values
pqmin = []  # Max-heap for minimum values

# Variables to store sums and minimum value
sumMin = 0
sumMax = 0
sumb = 0
min_val = 0

# Process each test case
for _ in range(t):
    # Read the input line and split it into parts
    s = input().strip().split()
    
    # If the first character is '2', calculate and print the result
    if s[0][0] == '2':
        ans = min_val
        ans *= len(pqmin)
        ans -= sumMin
        ans1 = min_val
        ans1 *= len(pqmax)
        ans1 = sumMax - ans1
        
        # Print the minimum value and the calculated result
        out(f"{min_val} {ans + ans1 + sumb}\n")
    else:
        # Parse the input values
        in_val = int(s[1])
        sumb += int(s[2])  # Update the sum of additional values
        
        # Add the input value to the appropriate priority queue
        if in_val > min_val:
            heapq.heappush(pqmax, in_val)
            sumMax += in_val
        else:
            heapq.heappush(pqmin, -in_val)
            sumMin += in_val
        
        # Balance the two heaps if necessary
        if len(pqmin) > len(pqmax):
            heapq.heappush(pqmax, -heapq.heappop(pqmin))
            sumMax += heapq.heappop(pqmin)
            sumMin -= heapq.heappop(pqmin)
        if len(pqmax) > len(pqmin):
            heapq.heappush(pqmin, -heapq.heappop(pqmax))
            sumMin += heapq.heappop(pqmax)
            sumMax -= heapq.heappop(pqmax)
        
        # Update the minimum value based on the current state of the heaps
        min_val = -pqmin[0]

# Close the output stream
out.flush()
