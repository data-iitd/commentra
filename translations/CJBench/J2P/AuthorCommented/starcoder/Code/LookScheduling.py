import sys

class Main:
    def __init__(self, startPosition, movingUp, maxTrack):
        self.currentPosition = startPosition
        self.movingUp = movingUp
        self.maxTrack = maxTrack
        self.farthestPosition = startPosition

    def execute(self, requests):
        result = []
        lower = []
        upper = []

        # Split requests into two lists based on their position relative to current position
        for request in requests:
            if request >= 0 and request < self.maxTrack:
                if request < self.currentPosition:
                    lower.append(request)
                else:
                    upper.append(request)

        # Sort the requests
        lower.sort()
        upper.sort()

        # Process the requests depending on the initial moving direction
        if self.movingUp:
            # Process requests in the upward direction
            result.extend(upper)
            if len(upper) > 0:
                self.farthestPosition = upper[len(upper) - 1]

            # Reverse the direction and process downward
            self.movingUp = False
            lower.reverse()
            result.extend(lower)
            if len(lower) > 0:
                self.farthestPosition = max(self.farthestPosition, lower[0])
        else:
            # Process requests in the downward direction
            lower.reverse()
            result.extend(lower)
            if len(lower) > 0:
                self.farthestPosition = lower[0]

            # Reverse the direction and process upward
            self.movingUp = True
            result.extend(upper)
            if len(upper) > 0:
                self.farthestPosition = max(self.farthestPosition, upper[len(upper) - 1])

        return result

if __name__ == "__main__":
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

    scheduler = Main(startPosition, movingUp, maxTrack)
    result = scheduler.execute(requests)

    # Output the processed order of requests
    for r in result:
        print(r, end=" ")

