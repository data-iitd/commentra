import sys

class Main:
    def __init__(self, startPosition, movingUp, maxTrack):
        self.currentPosition = startPosition
        self.movingUp = movingUp
        self.maxTrack = maxTrack

    def execute(self, requests):
        result = []
        lower = []
        upper = []
        for request in requests:
            if request >= 0 and request < self.maxTrack:
                if request < self.currentPosition:
                    lower.append(request)
                else:
                    upper.append(request)
        lower.sort()
        upper.sort()
        if self.movingUp:
            result.extend(upper)
            if len(upper) > 0:
                self.farthestPosition = upper[len(upper) - 1]
            self.movingUp = False
            lower.reverse()
            result.extend(lower)
            if len(lower) > 0:
                self.farthestPosition = max(self.farthestPosition, lower[0])
        else:
            lower.reverse()
            result.extend(lower)
            if len(lower) > 0:
                self.farthestPosition = lower[0]
            self.movingUp = True
            result.extend(upper)
            if len(upper) > 0:
                self.farthestPosition = max(self.farthestPosition, upper[len(upper) - 1])
        return result

if __name__ == "__main__":
    maxTrack = int(sys.stdin.readline())
    startPosition = int(sys.stdin.readline())
    movingUp = int(sys.stdin.readline()) == 1
    numRequests = int(sys.stdin.readline())
    requests = []
    for i in range(numRequests):
        requests.append(int(sys.stdin.readline()))
    scheduler = Main(startPosition, movingUp, maxTrack)
    result = scheduler.execute(requests)
    for r in result:
        print(r, end=" ")

