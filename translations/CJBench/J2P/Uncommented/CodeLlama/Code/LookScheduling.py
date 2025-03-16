import sys

class Main:
    def __init__(self, start_position, initial_direction, max_track):
        self.current_position = start_position
        self.moving_up = initial_direction
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
            lower.reverse()
            result.extend(lower)
            if lower:
                self.farthest_position = max(self.farthest_position, lower[0])
        else:
            lower.reverse()
            result.extend(lower)
            if lower:
                self.farthest_position = lower[0]
            self.moving_up = True
            result.extend(upper)
            if upper:
                self.farthest_position = max(self.farthest_position, upper[-1])
        return result

if __name__ == "__main__":
    max_track = int(sys.stdin.readline().strip())
    start_position = int(sys.stdin.readline().strip())
    moving_up = sys.stdin.readline().strip() == "1"
    num_requests = int(sys.stdin.readline().strip())
    requests = []
    for i in range(num_requests):
        requests.append(int(sys.stdin.readline().strip()))
    scheduler = Main(start_position, moving_up, max_track)
    result = scheduler.execute(requests)
    for r in result:
        print(r, end=" ")
    # 