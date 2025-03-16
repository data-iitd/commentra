
import sys

# Read input from the user
maxTrack = int(sys.stdin.readline().strip())
startPosition = int(sys.stdin.readline().strip())
movingUp = sys.stdin.readline().strip() == "1"
numRequests = int(sys.stdin.readline().strip())
requests = []
for i in range(numRequests):
    requests.append(int(sys.stdin.readline().strip()))

# Create an instance of the Main class and execute the requests
scheduler = Main(startPosition, movingUp, maxTrack)
result = scheduler.execute(requests)

# Print the result to the console
for r in result:
    print(r, end=" ")

# 