import sys

# Input maximum track size
maxTrack = int(sys.stdin.readline())

# Input current position of the disk head
startPosition = int(sys.stdin.readline())

# Input initial direction (1 for up, 0 for down)
movingUp = int(sys.stdin.readline()) == 1

# Input the number of requests
numRequests = int(sys.stdin.readline())
requests = []

# Input the requests
for i in range(numRequests):
    requests.append(int(sys.stdin.readline()))

# Execute the Look Scheduling algorithm
result = []
lower = []
upper = []

# Split requests into two lists based on their position relative to current position
for request in requests:
    if request >= 0 and request < maxTrack:
        if request < startPosition:
            lower.append(request)
        else:
            upper.append(request)

# Sort the requests
lower.sort()
upper.sort()

# Process the requests depending on the initial moving direction
if movingUp:
    # Process requests in the upward direction
    result.extend(upper)
    if upper:
        farthestPosition = upper[-1]

    # Reverse the direction and process downward
    movingUp = False
    upper.reverse()
    result.extend(upper)
    if upper:
        farthestPosition = max(farthestPosition, upper[0])
else:
    # Process requests in the downward direction
    upper.reverse()
    result.extend(upper)
    if upper:
        farthestPosition = upper[0]

    # Reverse the direction and process upward
    movingUp = True
    lower.reverse()
    result.extend(lower)
    if lower:
        farthestPosition = max(farthestPosition, lower[-1])

# Output the processed order of requests
for r in result:
    print(r, end=" ")

# 