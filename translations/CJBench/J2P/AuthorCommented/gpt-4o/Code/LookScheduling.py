import sys

class LookScheduler:
    def __init__(self, start_position, initial_direction, max_track):
        self.max_track = max_track
        self.current_position = start_position
        self.moving_up = initial_direction
        self.farthest_position = None

    def execute(self, requests):
        result = []
        lower = []
        upper = []

        # Split requests into two lists based on their position relative to current position
        for request in requests:
            if 0 <= request < self.max_track:
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
            lower.reverse()
            result.extend(lower)
            if lower:
                self.farthest_position = max(self.farthest_position, lower[0]) if self.farthest_position is not None else lower[0]
        else:
            # Process requests in the downward direction
            lower.reverse()
            result.extend(lower)
            if lower:
                self.farthest_position = lower[0]

            # Reverse the direction and process upward
            self.moving_up = True
            result.extend(upper)
            if upper:
                self.farthest_position = max(self.farthest_position, upper[-1]) if self.farthest_position is not None else upper[-1]

        return result

def main():
    # Input maximum track size
    max_track = int(input().strip())

    # Input current position of the disk head
    start_position = int(input().strip())

    # Input initial direction (1 for up, 0 for down)
    moving_up = int(input().strip()) == 1

    # Input the number of requests
    num_requests = int(input().strip())
    requests = []

    # Input the requests
    for _ in range(num_requests):
        requests.append(int(input().strip()))

    scheduler = LookScheduler(start_position, moving_up, max_track)
    result = scheduler.execute(requests)

    # Output the processed order of requests
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
