
import sys

# Define a class to store process details
class Process:
    def __init__(self, name, arrival_time, burst_time):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.turn_around_time = 0
        self.finished = False

    # Method to calculate response ratio
    def calculate_response_ratio(self, current_time):
        return (self.burst_time + current_time - self.arrival_time) / self.burst_time

# Main method to execute the program
def main():
    no_of_processes = int(sys.stdin.readline())
    process_names = []
    arrival_times = []
    burst_times = []
    for i in range(no_of_processes):
        process_names.append(sys.stdin.readline().strip())
        arrival_times.append(int(sys.stdin.readline()))
        burst_times.append(int(sys.stdin.readline()))
    turn_around_times = calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes)
    waiting_times = calculate_waiting_time(turn_around_times, burst_times)
    print("Process WaitingTime TurnAroundTime")
    for i in range(no_of_processes):
        print(process_names[i] + " " + str(waiting_times[i]) + " " + str(turn_around_times[i]))

# Method to calculate turn around times
def calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes):
    current_time = 0
    turn_around_time = [0] * no_of_processes
    processes = [Process(process_names[i], arrival_times[i], burst_times[i]) for i in range(no_of_processes)]
    processes.sort(key=lambda p: p.arrival_time)
    finished_process_count = 0
    while finished_process_count < no_of_processes:
        next_process_index = find_next_process(processes, current_time)
        if next_process_index == -1:
            current_time += 1
            continue
        current_process = processes[next_process_index]
        current_time = max(current_time, current_process.arrival_time)
        current_process.turn_around_time = current_time + current_process.burst_time - current_process.arrival_time
        current_time += current_process.burst_time
        current_process.finished = True
        finished_process_count += 1
    for i in range(no_of_processes):
        turn_around_time[i] = processes[i].turn_around_time
    return turn_around_time

# Method to calculate waiting times
def calculate_waiting_time(turn_around_time, burst_times):
    waiting_time = [0] * len(turn_around_time)
    for i in range(len(turn_around_time)):
        waiting_time[i] = turn_around_time[i] - burst_times[i]
    return waiting_time

# Method to find the next process to execute
def find_next_process(processes, current_time):
    return find_highest_response_ratio(processes, current_time)

# Method to find the process with the highest response ratio
def find_highest_response_ratio(processes, current_time):
    max_response_ratio = -1.0
    max_index = -1
    for i in range(len(processes)):
        process = processes[i]
        if not process.finished and process.arrival_time <= current_time:
            response_ratio = process.calculate_response_ratio(current_time)
            if response_ratio > max_response_ratio:
                max_response_ratio = response_ratio
                max_index = i
    return max_index

if __name__ == "__main__":
    main()

