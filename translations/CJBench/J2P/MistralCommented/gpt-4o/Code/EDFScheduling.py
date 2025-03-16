class Process:
    def __init__(self, process_id, burst_time, deadline):
        self.process_id = process_id
        self.burst_time = burst_time
        self.deadline = deadline
        self.waiting_time = 0
        self.turn_around_time = 0

    def get_process_id(self):
        return self.process_id

    def get_burst_time(self):
        return self.burst_time

    def get_deadline(self):
        return self.deadline

    def get_waiting_time(self):
        return self.waiting_time

    def set_waiting_time(self, waiting_time):
        self.waiting_time = waiting_time

    def get_turn_around_time(self):
        return self.turn_around_time

    def set_turn_around_time(self, turn_around_time):
        self.turn_around_time = turn_around_time


def schedule_processes(processes):
    # Sort the list of processes based on their deadlines
    processes.sort(key=lambda p: p.get_deadline())

    current_time = 0
    executed_processes = []

    for process in processes:
        # Calculate the waiting time and turnaround time for the current process
        process.set_waiting_time(current_time)
        current_time += process.get_burst_time()
        process.set_turn_around_time(process.get_waiting_time() + process.get_burst_time())

        # Check if the current process missed its deadline
        if current_time > process.get_deadline():
            print(f"Warning: Process {process.get_process_id()} missed its deadline.")

        # Add the executed process to the list of executed processes
        executed_processes.append(process)

    return executed_processes


def main():
    # Read the number of processes from the input
    num_processes = int(input())

    # Initialize a list to store the Process objects
    processes = []

    # Read the details of each process and add it to the list
    for _ in range(num_processes):
        process_id, burst_time, deadline = input().split()
        processes.append(Process(process_id, int(burst_time), int(deadline)))

    # Schedule the processes and print the results
    executed_processes = schedule_processes(processes)
    for process in executed_processes:
        print(f"{process.get_process_id()} {process.get_waiting_time()} {process.get_turn_around_time()}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
