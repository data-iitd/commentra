
import sys

class Process:
    def __init__(self, pid, burst_time, arrival_time):
        self.pid = pid
        self.burst_time = burst_time
        self.remaining_time = burst_time
        self.arrival_time = arrival_time
        self.priority = 0

    def execute(self, time_slice):
        self.remaining_time -= time_slice
        if self.remaining_time < 0:
            self.remaining_time = 0

    def is_finished(self):
        return self.remaining_time == 0

class Main:
    def __init__(self, levels, time_quantums):
        self.queues = [[] for _ in range(levels)]
        self.time_quantums = time_quantums
        self.current_time = 0

    def add_process(self, p):
        self.queues[0].append(p)

    def run(self):
        while not self.all_queues_empty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if queue:
                    p = queue.pop(0)
                    time_slice = min(self.time_quantums[i], p.remaining_time)
                    p.execute(time_slice)
                    self.current_time += time_slice

                    if p.is_finished():
                        print(f"Process {p.pid} finished at time {self.current_time}")
                    else:
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].append(p)
                        else:
                            queue.append(p)

    def all_queues_empty(self):
        return all(not queue for queue in self.queues)

if __name__ == "__main__":
    levels = int(sys.stdin.readline().strip())
    time_quantums = list(map(int, sys.stdin.readline().strip().split()))

    scheduler = Main(levels, time_quantums)

    n = int(sys.stdin.readline().strip())
    for _ in range(n):
        pid, burst_time, arrival_time = map(int, sys.stdin.readline().strip().split())
        scheduler.add_process(Process(pid, burst_time, arrival_time))

    scheduler.run()

