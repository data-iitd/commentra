from collections import deque

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
        self.queues = [deque() for _ in range(levels)]
        self.time_quantum = time_quantums
        self.current_time = 0

    def add_process(self, p):
        self.queues[0].append(p)

    def run(self):
        while not self.all_queues_empty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if queue:
                    p = queue.popleft()
                    quantum = self.time_quantum[i]
                    time_slice = min(quantum, p.remaining_time)
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
    import sys
    input = sys.stdin.read
    data = input().split()
    
    levels = int(data[0])
    time_quantums = list(map(int, data[1:levels+1]))
    n = int(data[levels+1])
    
    scheduler = Main(levels, time_quantums)
    
    index = levels + 2
    for _ in range(n):
        pid = int(data[index])
        burst_time = int(data[index + 1])
        arrival_time = int(data[index + 2])
        scheduler.add_process(Process(pid, burst_time, arrival_time))
        index += 3
    
    scheduler.run()
