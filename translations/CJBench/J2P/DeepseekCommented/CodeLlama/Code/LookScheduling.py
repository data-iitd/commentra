
import sys

# The maximum track number the elevator can reach
max_track = int(sys.stdin.readline().strip())
# The current position of the elevator
current_position = int(sys.stdin.readline().strip())
# Indicates the direction in which the elevator is moving
moving_up = sys.stdin.readline().strip() == "1"
# The farthest position reached by the elevator
farthest_position = current_position

# Constructor to initialize the elevator's state
def __init__(self, start_position, initial_direction, max_track):
    self.current_position = start_position
    self.moving_up = initial_direction
    self.max_track = max_track

# Method to execute the elevator's movement based on the requests
def execute(self, requests):
    # List to store the order of requests
    result = []
    # Lists to store requests categorized by their position relative to the current position
    lower = []
    upper = []

    # Categorize requests based on their position
    for request in requests:
        if request >= 0 and request < self.max_track:
            if request < self.current_position:
                lower.append(request)
            else:
                upper.append(request)

    # Sort the lists of requests
    lower.sort()
    upper.sort()

    # Execute the requests based on the current direction
    if self.moving_up:
        result.extend(upper)  # Add requests to be served in the current direction
        if upper:
            self.farthest_position = upper[-1]  # Update the farthest position
        self.moving_up = False  # Change the direction
        lower.reverse()  # Reverse the lower list for serving in the opposite direction
        result.extend(lower)  # Add requests to be served in the opposite direction
        if lower:
            self.farthest_position = max(self.farthest_position, lower[0])  # Update the farthest position
    else:
        lower.reverse()  # Reverse the lower list for serving in the current direction
        result.extend(lower)  # Add requests to be served in the current direction
        if lower:
            self.farthest_position = lower[0]  # Update the farthest position
        self.moving_up = True  # Change the direction
        result.extend(upper)  # Add requests to be served in the new direction
        if upper:
            self.farthest_position = max(self.farthest_position, upper[-1])  # Update the farthest position

    return result

# Main method to run the elevator simulation
def main():
    start_position = int(sys.stdin.readline().strip())
    initial_direction = sys.stdin.readline().strip() == "1"
    num_requests = int(sys.stdin.readline().strip())
    requests = []
    for i in range(num_requests):
        requests.append(int(sys.stdin.readline().strip()))
    scheduler = Main(start_position, initial_direction, max_track)
    result = scheduler.execute(requests)
    for r in result:
        print(r, end=" ")

if __name__ == "__main__":
    main()
    print("