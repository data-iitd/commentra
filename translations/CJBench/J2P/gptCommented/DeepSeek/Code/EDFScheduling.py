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
    # Sort the processes based on their deadlines
    processes.sort(key=lambda x: x.get_deadline())

    # Initialize the current time to track the scheduling
    current_time = 0

    # List to hold the processes that have been executed
    executed_processes = []

    # Loop through each process to calculate waiting and turnaround times
    for process in processes:
        # Set the waiting time for the current process
        process.set_waiting_time(current_time)

        # Update the current time by adding the burst time of the current process
        current_time += process.get_burst_time()

        # Calculate the turnaround time for the current process
        process.set_turn_around_time(process.get_waiting_time() + process.get_burst_time())

        # Check if the process has missed its deadline and print a warning if so
        if current_time > process.get_deadline():
            print(f"Warning: Process {process.get_process_id()} missed its deadline.")

        # Add the current process to the list of executed processes
        executed_processes.append(process)

    # Return the list of executed processes
    return executed_processes


# Main function to read input, schedule processes, and output results
def main():
    # Create a Scanner object to read input from the console
    import sys
    input = sys.stdin.readline

    # Read the number of processes to be scheduled
    num_processes = int(input().strip())

    # Initialize a list to hold the processes
    processes = []

    # Loop to read each process's details
    for _ in range(num_processes):
        process_id, burst_time, deadline = input().strip().split()
        processes.append(Process(process_id, int(burst_time), int(deadline)))

    # Schedule the processes and get the list of executed processes
    executed_processes = schedule_processes(processes)

    # Output the results for each executed process
    for process in executed_processes:
        print(f"{process.get_process_id()} {process.get_waiting_time()} {process.get_turn_around_time()}")


# Call the main function to execute the program
if __name__ == "__main__":
    main()
