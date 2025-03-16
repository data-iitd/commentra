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
    # Sort the list based on deadlines
    processes.sort(key=lambda process: process.get_deadline())

    # Initialize variables for current time and executed processes
    current_time = 0
    executed_processes = []

    # Iterate through the sorted list of processes and execute them
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

    # Return the list of executed processes
    return executed_processes


# Main function to read input and schedule processes
def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the number of processes from the input
    num_processes = int(data[0])
    index = 1

    # Initialize a list to store the Process objects
    processes = []

    # Read the details of each process and add it to the list
    for i in range(num_processes):
        process_id = data[index]
        burst_time = int(data[index + 1])
        deadline = int(data[index + 2])
        processes.append(Process(process_id, burst_time, deadline))
        index += 3

    # Schedule the processes and print the results
    executed_processes = schedule_processes(processes)
    for process in executed_processes:
        print(f"{process.get_process_id()} {process.get_waiting_time()} {process.get_turn_around_time()}")


# Call the main function
if __name__ == "__main__":
    main()
