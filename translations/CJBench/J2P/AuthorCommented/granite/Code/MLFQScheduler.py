
import queue

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
        self.queues = [queue.Queue() for _ in range(levels)]
        self.time_quantum = time_quantums
        self.current_time = 0

    def add_process(self, p):
        self.queues[0].put(p)

    def run(self):
        while not self.all_queues_empty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if not queue.empty():
                    p = queue.get()
                    time_slice = min(self.time_quantum[i], p.remaining_time)
                    p.execute(time_slice)
                    self.current_time += time_slice

                    if p.is_finished():
                        print(f"Process {p.pid} finished at time {self.current_time}")
                    else:
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].put(p)
                        else:
                            queue.put(p)

    def all_queues_empty(self):
        for queue in self.queues:
            if not queue.empty():
                return False
        return True

if __name__ == "__main__":
    import sys

    # Input number of queues and their time quantums
    levels = int(input())
    time_quantums = list(map(int, input().split()))

    main = Main(levels, time_quantums)

    # Input number of processes
    n = int(input())
    for _ in range(n):
        pid, burst_time, arrival_time = map(int, input().split())
        main.add_process(Process(pid, burst_time, arrival_time))

    main.run()

