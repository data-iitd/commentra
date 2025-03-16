
import sys

class Main:
    # Maximum track limit
    maxTrack = 0
    # Current position of the elevator
    currentPosition = 0
    # Direction of movement: true for up, false for down
    movingUp = False
    # Farthest position reached during the execution
    farthestPosition = 0

    # Constructor to initialize the elevator's starting position, direction, and track limit
    def __init__(self, startPosition, initialDirection, maxTrack):
        self.currentPosition = startPosition
        self.movingUp = initialDirection
        self.maxTrack = maxTrack

    # Method to execute the elevator requests and return the order of service
    def execute(self, requests):
        # List to store the result of the order of service
        result = []
        # Lists to hold requests below and above the current position
        lower = []
        upper = []

        # Separate requests into lower and upper based on the current position
        for request in requests:
            if request >= 0 and request < self.maxTrack: # Validate request within track limits
                if request < self.currentPosition:
                    lower.append(request) # Add to lower if below current position
                else:
                    upper.append(request) # Add to upper if above or at current position
        # Sort the lower and upper requests
        lower.sort()
        upper.sort()

        # Process requests based on the current direction of movement
        if self.movingUp:
            # If moving up, serve all upper requests first
            result.extend(upper)
            if upper:
                self.farthestPosition = upper[-1] # Update farthest position
            self.movingUp = False # Change direction to down
            upper.reverse() # Reverse lower requests to serve them in descending order
            result.extend(upper)
            if upper:
                self.farthestPosition = max(self.farthestPosition, upper[0]) # Update farthest position
        else:
            # If moving down, serve all lower requests first
            upper.reverse() # Reverse lower requests to serve them in descending order
            result.extend(upper)
            if upper:
                self.farthestPosition = upper[0] # Update farthest position
            self.movingUp = True # Change direction to up
            result.extend(lower) # Serve lower requests next
            if lower:
                self.farthestPosition = max(self.farthestPosition, lower[-1]) # Update farthest position
        return result # Return the order of service

    # Main method to run the elevator simulation
    @staticmethod
    def main():
        # Read maximum track limit, starting position, initial direction, and number of requests
        maxTrack = int(input())
        startPosition = int(input())
        movingUp = int(input()) # Convert input to boolean
        numRequests = int(input())

        # Read the requests into a list
        requests = []
        for _ in range(numRequests):
            requests.append(int(input()))

        # Create an instance of the Main class (elevator scheduler)
        scheduler = Main(startPosition, movingUp, maxTrack)

        # Execute the requests and get the result
        result = scheduler.execute(requests)

        # Print the result of the order of service
        print(" ".join(map(str, result)))

if __name__ == "__main__":
    Main.main()

