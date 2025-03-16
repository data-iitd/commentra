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
        self.time_quantum = time_quantums
        self.current_time = 0

    def add_process(self, process):
        self.queues[0].append(process)

    def run(self):
        while not self.all_queues_empty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if queue:
                    process = queue.pop(0)
                    quantum = self.time_quantum[i]
                    time_slice = min(quantum, process.remaining_time)
                    process.execute(time_slice)
                    self.current_time += time_slice

                    if process.is_finished():
                        print(f"Process {process.pid} finished at time {self.current_time}")
                    else:
                        if i < len(self.queues) - 1:
                            process.priority += 1
                            self.queues[i + 1].append(process)
                        else:
                            queue.append(process)

    def all_queues_empty(self):
        return all(not queue for queue in self.queues)


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    levels = int(data[0])
    time_quantums = list(map(int, data[1:levels + 1]))
    n = int(data[levels + 1])
    processes = []

    for i in range(n):
        pid = int(data[levels + 2 + 3 * i])
        burst_time = int(data[levels + 3 + 3 * i])
        arrival_time = int(data[levels + 4 + 3 * i])
        processes.append(Process(pid, burst_time, arrival_time))

    scheduler = Main(levels, time_quantums)
    for process in processes:
        scheduler.add_process(process)

    scheduler.run()
