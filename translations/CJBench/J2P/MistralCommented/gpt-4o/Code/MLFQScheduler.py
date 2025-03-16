from collections import deque

class Process:
    def __init__(self, pid, burst_time, arrival_time):
        self.pid = pid  # Process ID
        self.burst_time = burst_time  # Burst time of the process
        self.remaining_time = burst_time  # Remaining time of the process
        self.arrival_time = arrival_time  # Arrival time of the process
        self.priority = 0  # Priority of the process

    def execute(self, time_slice):
        self.remaining_time -= time_slice  # Decrement the remaining time by the given time slice
        if self.remaining_time < 0:
            self.remaining_time = 0  # Set the remaining time to zero if it becomes negative

    def is_finished(self):
        return self.remaining_time == 0  # Check if the process is finished


class Scheduler:
    def __init__(self, levels, time_quantums):
        self.queues = [deque() for _ in range(levels)]  # Initialize an empty queue for each level
        self.time_quantum = time_quantums  # Time quantum for each level
        self.current_time = 0  # Current time initialized to zero

    def add_process(self, p):
        self.queues[0].append(p)  # Add a process to the first queue

    def run(self):
        while not self.all_queues_empty():  # Loop until all queues are empty
            for i in range(len(self.queues)):
                queue = self.queues[i]  # Get the queue for the current level
                if queue:  # If the queue is not empty
                    p = queue.popleft()  # Dequeue the process
                    quantum = self.time_quantum[i]  # Get the time quantum for the current level
                    time_slice = min(quantum, p.remaining_time)  # Calculate the time slice
                    p.execute(time_slice)  # Execute the process for the calculated time slice
                    self.current_time += time_slice  # Increment the current time

                    if p.is_finished():  # Check if the process is finished
                        print(f"Process {p.pid} finished at time {self.current_time}")
                    else:
                        if i < len(self.queues) - 1:  # If there is a next level
                            p.priority += 1  # Increment the priority
                            self.queues[i + 1].append(p)  # Add the process to the next queue
                        else:  # Otherwise, add the process back to the current queue
                            queue.append(p)

    def all_queues_empty(self):
        return all(not queue for queue in self.queues)  # Check if all queues are empty


if __name__ == "__main__":
    levels = int(input("Enter number of levels: "))  # Read the number of levels
    time_quantums = list(map(int, input("Enter time quanta for each level: ").split()))  # Read time quanta for each level

    scheduler = Scheduler(levels, time_quantums)  # Create a scheduler instance

    n = int(input("Enter number of processes: "))  # Read the number of processes
    for _ in range(n):
        pid, burst_time, arrival_time = map(int, input("Enter PID, Burst Time, Arrival Time: ").split())
        scheduler.add_process(Process(pid, burst_time, arrival_time))  # Add each process to the scheduler

    scheduler.run()  # Start the scheduler

# <END-OF-CODE>
