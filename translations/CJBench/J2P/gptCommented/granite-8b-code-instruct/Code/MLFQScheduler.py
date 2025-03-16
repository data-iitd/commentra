
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
        while not all(q.empty() for q in self.queues):
            for i in range(len(self.queues)):
                q = self.queues[i]
                if not q.empty():
                    p = q.get()
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
                            q.put(p)

    def all_queues_empty(self):
        return all(q.empty() for q in self.queues)

if __name__ == "__main__":
    import sys
    scanner = iter(sys.stdin.read().splitlines())

    levels = int(next(scanner))
    time_quantums = [int(x) for x in next(scanner).split()]
    main = Main(levels, time_quantums)

    n = int(next(scanner))
    for _ in range(n):
        pid, burst_time, arrival_time = map(int, next(scanner).split())
        main.add_process(Process(pid, burst_time, arrival_time))

    main.run()

