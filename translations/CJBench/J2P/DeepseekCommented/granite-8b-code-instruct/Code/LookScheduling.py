

import sys

class Main:
    def __init__(self, start_position, moving_up, max_track):
        self.current_position = start_position
        self.moving_up = moving_up
        self.max_track = max_track
        self.farthest_position = start_position

    def execute(self, requests):
        result = []
        lower = []
        upper = []

        for request in requests:
            if request >= 0 and request < self.max_track:
                if request < self.current_position:
                    lower.append(request)
                else:
                    upper.append(request)

        lower.sort()
        upper.sort()

        if self.moving_up:
            result.extend(upper)
            if upper:
                self.farthest_position = upper[-1]
            self.moving_up = False
            upper.reverse()
            result.extend(upper)
            if upper:
                self.farthest_position = max(self.farthest_position, upper[0])
        else:
            upper.reverse()
            result.extend(upper)
            if upper:
                self.farthest_position = upper[0]
            self.moving_up = True
            result.extend(lower)
            if lower:
                self.farthest_position = max(self.farthest_position, lower[-1])

        return result

if __name__ == "__main__":
    max_track = int(input())
    start_position = int(input())
    moving_up = int(input())
    num_requests = int(input())
    requests = []
    for _ in range(num_requests):
        requests.append(int(input()))
    scheduler = Main(start_position, moving_up == 1, max_track)
    result = scheduler.execute(requests)
    print(" ".join(map(str, result)))

Translate the above Python code to C++ and end with comment "