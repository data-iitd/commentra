from typing import List

class Main:
    def __init__(self, start_position: int, initial_direction: bool, max_track: int):
        self.max_track = max_track
        self.current_position = start_position
        self.moving_up = initial_direction
        self.farthest_position = start_position

    def execute(self, requests: List[int]) -> List[int]:
        result = []  # Initialize an empty result list
        lower = []   # Initialize an empty list for requests lower than the current position
        upper = []   # Initialize an empty list for requests higher than the current position

        # Iterate through the requests and sort them accordingly
        for request in requests:
            if 0 <= request < self.max_track:  # Check if the request is valid
                if request < self.current_position:  # If the request is lower than the current position
                    lower.append(request)
                else:  # If the request is higher than the current position
                    upper.append(request)

        # Sort the lower and upper lists
        lower.sort()
        upper.sort()

        # Determine the direction and update the farthest position
        if self.moving_up:  # If moving up
            result.extend(upper)  # Add the upper list to the result
            if upper:
                self.farthest_position = upper[-1]
            self.moving_up = False  # Reverse the direction for the next iteration
            result.extend(reversed(lower))  # Add the reversed lower list to the result
            if lower:
                self.farthest_position = max(self.farthest_position, lower[0])  # Update the farthest position
        else:  # If moving down
            result.extend(reversed(lower))  # Add the reversed lower list to the result
            if lower:
                self.farthest_position = lower[0]
            self.moving_up = True  # Reverse the direction for the next iteration
            result.extend(upper)  # Add the upper list to the result
            if upper:
                self.farthest_position = max(self.farthest_position, upper[-1])

        return result  # Return the final result

if __name__ == "__main__":
    max_track = int(input())  # Read maximum track length
    start_position = int(input())  # Read initial position
    moving_up = int(input()) == 1  # Read initial direction
    num_requests = int(input())  # Read number of requests
    requests = [int(input()) for _ in range(num_requests)]  # Read requests

    # Create an instance of the Main class and execute the requests
    scheduler = Main(start_position, moving_up, max_track)
    result = scheduler.execute(requests)

    # Print the result to the console
    print(" ".join(map(str, result)))  # Print the result as space-separated values

# <END-OF-CODE>
