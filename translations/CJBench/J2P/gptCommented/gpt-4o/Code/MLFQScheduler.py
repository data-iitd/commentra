from collections import deque

class Process:
    def __init__(self, pid, burst_time, arrival_time):
        self.pid = pid  # Process ID
        self.burst_time = burst_time  # Total burst time required for the process
        self.remaining_time = burst_time  # Initially, remaining time is equal to burst time
        self.arrival_time = arrival_time  # Arrival time of the process
        self.priority = 0  # Initial priority is set to 0

    def execute(self, time_slice):
        self.remaining_time -= time_slice  # Decrease the remaining time by the time slice
        if self.remaining_time < 0:
            self.remaining_time = 0  # Ensure remaining time does not go negative

    def is_finished(self):
        return self.remaining_time == 0  # Process is finished if remaining time is 0


class Scheduler:
    def __init__(self, levels, time_quantums):
        self.queues = [deque() for _ in range(levels)]  # List of queues for different priority levels
        self.time_quantum = time_quantums  # Time quantums for each priority level
        self.current_time = 0  # Start time at 0

    def add_process(self, p):
        self.queues[0].append(p)  # Add new process to the highest priority queue (queue 0)

    def run(self):
        while not self.all_queues_empty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if queue:  # If the current queue is not empty
                    p = queue.popleft()  # Get the next process from the queue
                    quantum = self.time_quantum[i]  # Get the time quantum for the current level
                    time_slice = min(quantum, p.remaining_time)  # Determine the time slice to execute

                    # Execute the process for the determined time slice
                    p.execute(time_slice)
                    self.current_time += time_slice  # Update the current time

                    # Check if the process has finished executing
                    if p.is_finished():
                        print(f"Process {p.pid} finished at time {self.current_time}")
                    else:
                        # If not finished and not at the last queue, increase priority and move to the next queue
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].append(p)  # Add to the next priority queue
                        else:
                            queue.append(p)  # If at the last queue, re-add to the same queue

    def all_queues_empty(self):
        return all(not queue for queue in self.queues)  # Check if all queues are empty


if __name__ == "__main__":
    levels = int(input("Enter number of priority levels: "))  # Read the number of priority levels
    time_quantums = list(map(int, input("Enter time quantums for each level: ").split()))  # Read time quantums
    scheduler = Scheduler(levels, time_quantums)  # Initialize the scheduler
    n = int(input("Enter number of processes: "))  # Read the number of processes to schedule
    for _ in range(n):
        pid, burst_time, arrival_time = map(int, input("Enter process ID, burst time, and arrival time: ").split())
        scheduler.add_process(Process(pid, burst_time, arrival_time))  # Add each process to the scheduler
    scheduler.run()  # Start the scheduling process
# <END-OF-CODE>
