
import sys

class Main:
    def __init__(self, start_position, initial_direction, max_track):
        self.current_position = start_position
        self.moving_up = initial_direction
        self.max_track = max_track

    def execute(self, requests):
        result = []
        lower = []
        upper = []

        # Split requests into two lists based on their position relative to current position
        for request in requests:
            if request >= 0 and request < self.max_track:
                if request < self.current_position:
                    lower.append(request)
                else:
                    upper.append(request)

        # Sort the requests
        lower.sort()
        upper.sort()

        # Process the requests depending on the initial moving direction
        if self.moving_up:
            # Process requests in the upward direction
            result.extend(upper)
            if upper:
                self.farthest_position = upper[-1]

            # Reverse the direction and process downward
            self.moving_up = False
            upper.reverse()
            result.extend(upper)
            if upper:
                self.farthest_position = max(self.farthest_position, upper[0])
        else:
            # Process requests in the downward direction
            upper.reverse()
            result.extend(upper)
            if upper:
                self.farthest_position = upper[0]

            # Reverse the direction and process upward
            self.moving_up = True
            result.extend(lower)
            if lower:
                self.farthest_position = max(self.farthest_position, lower[-1])

        return result

if __name__ == "__main__":
    # Input maximum track size
    max_track = int(input())

    # Input current position of the disk head
    start_position = int(input())

    # Input initial direction (1 for up, 0 for down)
    moving_up = int(input())

    # Input the number of requests
    num_requests = int(input())
    requests = []

    # Input the requests
    for _ in range(num_requests):
        requests.append(int(input()))

    scheduler = Main(start_position, moving_up, max_track)
    result = scheduler.execute(requests)

    # Output the processed order of requests
    print(" ".join(map(str, result)))

