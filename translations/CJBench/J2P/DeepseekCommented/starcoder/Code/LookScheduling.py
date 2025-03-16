
import sys

class Main:
    # The maximum track number the elevator can reach
    maxTrack = 0
    # The current position of the elevator
    currentPosition = 0
    # Indicates the direction in which the elevator is moving
    movingUp = True
    # The farthest position reached by the elevator
    farthestPosition = 0

    # Constructor to initialize the elevator's state
    def __init__(self, startPosition, initialDirection, maxTrack):
        self.currentPosition = startPosition
        self.movingUp = initialDirection
        self.maxTrack = maxTrack

    # Method to execute the elevator's movement based on the requests
    def execute(self, requests):
        # List to store the order of requests
        result = []
        # Lists to store requests categorized by their position relative to the current position
        lower = []
        upper = []

        # Categorize requests based on their position
        for request in requests:
            if request >= 0 and request < self.maxTrack:
                if request < self.currentPosition:
                    lower.append(request)
                else:
                    upper.append(request)

        # Sort the lists of requests
        lower.sort()
        upper.sort()

        # Execute the requests based on the current direction
        if self.movingUp:
            result.extend(upper) # Add requests to be served in the current direction
            if len(upper) > 0:
                self.farthestPosition = upper[len(upper) - 1] # Update the farthest position
            self.movingUp = False # Change the direction
            lower.reverse() # Reverse the lower list for serving in the opposite direction
            result.extend(lower) # Add requests to be served in the opposite direction
            if len(lower) > 0:
                self.farthestPosition = max(self.farthestPosition, lower[0]) # Update the farthest position
        else:
            lower.reverse() # Reverse the lower list for serving in the current direction
            result.extend(lower) # Add requests to be served in the current direction
            if len(lower) > 0:
                self.farthestPosition = lower[0] # Update the farthest position
            self.movingUp = True # Change the direction
            result.extend(upper) # Add requests to be served in the new direction
            if len(upper) > 0:
                self.farthestPosition = max(self.farthestPosition, upper[len(upper) - 1]) # Update the farthest position

        return result

if __name__ == "__main__":
    # Read the maximum track number
    maxTrack = int(sys.stdin.readline())
    # Read the starting position
    startPosition = int(sys.stdin.readline())
    # Read the initial direction
    movingUp = sys.stdin.readline().strip() == "1"
    # Read the number of requests
    numRequests = int(sys.stdin.readline())
    # Read each request
    requests = []
    for i in range(numRequests):
        requests.append(int(sys.stdin.readline()))
    scheduler = Main(startPosition, movingUp, maxTrack)
    result = scheduler.execute(requests)
    for r in result:
        print(r, end=" ") # Print the result

