import sys
import heapq

# Output stream for printing results
outputStream = sys.stdout

# Input stream for reading input from standard input
inputStream = sys.stdin

# Read the number of test cases
t = int(input())

# Arrays and priority queues for processing input
s = []
pqmax = [] # Min-heap for maximum values
pqmin = [] # Max-heap for minimum values

# Variables to store sums and minimum value
sumMin = 0
sumMax = 0
sumb = 0
min = 0

# Process each test case
while t > 0:
    # Read the input line and split it into parts
    s = input().split(" ")

    # If the first character is '2', calculate and print the result
    if s[0].charAt(0) == '2':
        ans = min
        ans *= len(pqmin)
        ans -= sumMin
        ans1 = min
        ans1 *= len(pqmax)
        ans1 = sumMax - ans1

        # Print the minimum value and the calculated result
        print(min, " ", ans + ans1 + sumb, end="")
    else:
        # Parse the input values
        in = int(s[1])
        sumb += int(s[2]) # Update the sum of additional values

        # Add the input value to the appropriate priority queue
        if in > min:
            heapq.heappush(pqmax, in)
            sumMax += in
        else:
            heapq.heappush(pqmin, in)
            sumMin += in

        # Balance the two heaps if necessary
        if len(pqmin) > len(pqmax):
            sumMax += pqmin[0]
            sumMin -= pqmin[0]
            heapq.heappush(pqmax, pqmin[0])
            pqmin.pop(0)
        if len(pqmin) < len(pqmax):
            sumMax -= pqmax[0]
            sumMin += pqmax[0]
            heapq.heappush(pqmin, pqmax[0])
            pqmax.pop(0)

        # Update the minimum value based on the current state of the heaps
        min = pqmin[0]

    t -= 1

# Close the output stream
outputStream.close()

