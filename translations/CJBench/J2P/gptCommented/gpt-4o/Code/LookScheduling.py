import sys

class Elevator:
    def __init__(self, start_position, initial_direction, max_track):
        self.max_track = max_track
        self.current_position = start_position
        self.moving_up = initial_direction
        self.farthest_position = start_position

    def execute(self, requests):
        result = []
        lower = []
        upper = []

        # Separate requests into lower and upper based on the current position
        for request in requests:
            if 0 <= request < self.max_track:  # Validate request within track limits
                if request < self.current_position:
                    lower.append(request)  # Add to lower if below current position
                else:
                    upper.append(request)  # Add to upper if above or at current position

        # Sort the lower and upper requests
        lower.sort()
        upper.sort()

        # Process requests based on the current direction of movement
        if self.moving_up:
            # If moving up, serve all upper requests first
            result.extend(upper)
            if upper:
                self.farthest_position = upper[-1]  # Update farthest position
            self.moving_up = False  # Change direction to down
            result.extend(reversed(lower))  # Serve lower requests in descending order
            if lower:
                self.farthest_position = max(self.farthest_position, lower[0])  # Update farthest position
        else:
            # If moving down, serve all lower requests first
            result.extend(reversed(lower))  # Serve lower requests in descending order
            if lower:
                self.farthest_position = lower[0]  # Update farthest position
            self.moving_up = True  # Change direction to up
            result.extend(upper)  # Serve upper requests next
            if upper:
                self.farthest_position = max(self.farthest_position, upper[-1])  # Update farthest position

        return result  # Return the order of service

def main():
    # Read maximum track limit, starting position, initial direction, and number of requests
    max_track = int(input())
    start_position = int(input())
    moving_up = int(input()) == 1  # Convert input to boolean
    num_requests = int(input())
    
    # Read the requests into a list
    requests = [int(input()) for _ in range(num_requests)]
    
    # Create an instance of the Elevator class (elevator scheduler)
    scheduler = Elevator(start_position, moving_up, max_track)
    
    # Execute the requests and get the result
    result = scheduler.execute(requests)
    
    # Print the result of the order of service
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
