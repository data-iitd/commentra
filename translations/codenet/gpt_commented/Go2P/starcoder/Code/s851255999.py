# <START-OF-CODE>

# Read the number of work items
n = int(input())

# Initialize a slice to hold the work items
ws = []

# Read each work item's time and limit
for i in range(n):
    a, n = map(int, input().split())
    ws.append((a, n)) # Store the work item in the slice

# Sort the work items based on their limits
ws.sort(key=lambda x: x[1])

# Initialize a variable to keep track of the cumulative time
sum = 0

# Check if the cumulative time exceeds the limit for any work item
for _, w in ws:
    sum += w[0] # Add the current work item's time to the sum
    if sum > w[1]:
        print("No") # If the sum exceeds the limit, print "No"
        break
else:
    print("Yes") # If all work items are within their limits, print "Yes"

# 