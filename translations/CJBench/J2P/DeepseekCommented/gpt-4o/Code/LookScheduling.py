class ElevatorScheduler:
    def __init__(self, start_position, initial_direction, max_track):
        self.max_track = max_track
        self.current_position = start_position
        self.moving_up = initial_direction
        self.farthest_position = start_position

    def execute(self, requests):
        result = []
        lower = []
        upper = []

        for request in requests:
            if 0 <= request < self.max_track:
                if request < self.current_position:
                    lower.append(request)
                else:
                    upper.append(request)

        lower.sort(reverse=True)
        upper.sort()

        if self.moving_up:
            result.extend(upper)
            if upper:
                self.farthest_position = max(self.farthest_position, upper[-1])
            self.moving_up = False
            result.extend(lower)
            if lower:
                self.farthest_position = max(self.farthest_position, lower[0])
        else:
            result.extend(lower)
            if lower:
                self.farthest_position = max(self.farthest_position, lower[0])
            self.moving_up = True
            result.extend(upper)
            if upper:
                self.farthest_position = max(self.farthest_position, upper[-1])

        return result


def main():
    max_track = int(input())
    start_position = int(input())
    moving_up = int(input()) == 1
    num_requests = int(input())
    requests = [int(input()) for _ in range(num_requests)]
    scheduler = ElevatorScheduler(start_position, moving_up, max_track)
    result = scheduler.execute(requests)
    for r in result:
        print(r, end=" ")


main()
