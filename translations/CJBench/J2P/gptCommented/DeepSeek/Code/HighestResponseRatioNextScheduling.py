import sys

# Constant to indicate that a process was not found
PROCESS_NOT_FOUND = -1
# Initial value for maximum response ratio
INITIAL_MAX_RESPONSE_RATIO = -1.0

# Class representing a process with its attributes
class Process:
    def __init__(self, name, arrival_time, burst_time):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.turn_around_time = 0
        self.finished = False

    # Method to calculate the response ratio of the process
    def calculate_response_ratio(self, current_time):
        return (self.burst_time + current_time - self.arrival_time) / self.burst_time

# Method to calculate turnaround times for all processes
def calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes):
    current_time = 0  # Initialize current time
    turn_around_time = [0] * no_of_processes  # Array to store turnaround times
    processes = [Process(process_names[i], arrival_times[i], burst_times[i]) for i in range(no_of_processes)]  # Array to hold process objects

    # Sort processes based on their arrival times
    processes.sort(key=lambda p: p.arrival_time)

    finished_process_count = 0  # Counter for finished processes

    # Process scheduling loop
    while finished_process_count < no_of_processes:
        # Find the next process to execute based on response ratio
        next_process_index = find_next_process(processes, current_time)
        if next_process_index == PROCESS_NOT_FOUND:
            # If no process is found, increment current time
            current_time += 1
            continue

        # Get the current process to execute
        current_process = processes[next_process_index]
        # Update current time to the arrival time of the current process if necessary
        current_time = max(current_time, current_process.arrival_time)
        # Calculate turnaround time for the current process
        current_process.turn_around_time = current_time + current_process.burst_time - current_process.arrival_time
        # Update current time after executing the current process
        current_time += current_process.burst_time
        # Mark the current process as finished
        current_process.finished = True
        finished_process_count += 1  # Increment the count of finished processes

    # Store the calculated turnaround times in the array
    for i in range(no_of_processes):
        turn_around_time[i] = processes[i].turn_around_time
    return turn_around_time  # Return the array of turnaround times

# Method to calculate waiting times based on turnaround times and burst times
def calculate_waiting_time(turn_around_time, burst_times):
    waiting_time = [0] * len(turn_around_time)  # Array to store waiting times
    # Calculate waiting time for each process
    for i in range(len(turn_around_time)):
        waiting_time[i] = turn_around_time[i] - burst_times[i]
    return waiting_time  # Return the array of waiting times

# Method to find the next process to execute based on response ratio
def find_next_process(processes, current_time):
    return find_highest_response_ratio(processes, current_time)  # Delegate to find highest response ratio

# Method to find the process with the highest response ratio
def find_highest_response_ratio(processes, current_time):
    max_response_ratio = INITIAL_MAX_RESPONSE_RATIO  # Initialize maximum response ratio
    max_index = PROCESS_NOT_FOUND  # Index of the process with the highest response ratio

    # Iterate through processes to find the one with the highest response ratio
    for i in range(len(processes)):
        process = processes[i]
        # Check if the process is not finished and has arrived
        if not process.finished and process.arrival_time <= current_time:
            response_ratio = process.calculate_response_ratio(current_time)
            # Update maximum response ratio and index if a higher one is found
            if response_ratio > max_response_ratio:
                max_response_ratio = response_ratio
                max_index = i
    return max_index  # Return the index of the process with the highest response ratio

# Main function to read input and print results
def main():
    # Read the number of processes
    no_of_processes = int(input())
    process_names = []
    arrival_times = []
    burst_times = []

    # Read process details from user input
    for _ in range(no_of_processes):
        process_names.append(input().strip())
        arrival_times.append(int(input().strip()))
        burst_times.append(int(input().strip()))

    # Calculate turnaround times for the processes
    turn_around_times = calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes)
    # Calculate waiting times based on turnaround times
    waiting_times = calculate_waiting_time(turn_around_times, burst_times)

    # Print the waiting and turnaround times for each process
    print("Process WaitingTime TurnAroundTime")
    for i in range(no_of_processes):
        print(f"{process_names[i]} {waiting_times[i]} {turn_around_times[i]}")

if __name__ == "__main__":
    main()
