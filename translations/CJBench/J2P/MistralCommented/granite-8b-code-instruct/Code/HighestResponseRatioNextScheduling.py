

import sys
from typing import List

# Constants for special values
PROCESS_NOT_FOUND = -1
INITIAL_MAX_RESPONSE_RATIO = -1.0

# Class for process information
class Process:
    def __init__(self, name: str, arrival_time: int, burst_time: int):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.turn_around_time = 0
        self.finished = False

    def calculate_response_ratio(self, current_time: int) -> float:
        return (self.burst_time + current_time - self.arrival_time) / self.burst_time

def calculate_turn_around_time(process_names: List[str], arrival_times: List[int], burst_times: List[int], no_of_processes: int) -> List[int]:
    current_time = 0  # Current time
    turn_around_time = [0] * no_of_processes  # Array to store turnaround times
    processes = [Process(name, arrival_time, burst_time) for name, arrival_time, burst_time in zip(process_names, arrival_times, burst_times)]  # Initialize process objects

    # Sort processes based on arrival times
    processes.sort(key=lambda p: p.arrival_time)

    finished_process_count = 0  # Number of finished processes

    # Simulate CPU scheduling
    while finished_process_count < no_of_processes:
        next_process_index = find_next_process(processes, current_time)

        if next_process_index == PROCESS_NOT_FOUND:
            current_time += 1  # Increment current time if no process is ready
            continue

        current_process = processes[next_process_index]  # Get the next process
        current_time = max(current_time, current_process.arrival_time)  # Set current time to the arrival time of the next process

        current_process.turn_around_time = current_time + current_process.burst_time - current_process.arrival_time  # Calculate turnaround time
        current_time += current_process.burst_time  # Increment current time by burst time of the current process
        current_process.finished = True  # Mark the current process as finished
        finished_process_count += 1  # Increment finished process count

    return turn_around_time  # Return the array of turnaround times

def calculate_waiting_time(turn_around_time: List[int], burst_times: List[int]) -> List[int]:
    waiting_time = [0] * len(turn_around_time)  # Array to store waiting times

    for i in range(len(turn_around_time)):
        waiting_time[i] = turn_around_time[i] - burst_times[i]  # Calculate waiting time for each process

    return waiting_time  # Return the array of waiting times

def find_next_process(processes: List[Process], current_time: int) -> int:
    max_response_ratio = INITIAL_MAX_RESPONSE_RATIO  # Initialize maximum response ratio
    max_index = PROCESS_NOT_FOUND  # Initialize index of the process with the maximum response ratio

    for i in range(len(processes)):
        process = processes[i]  # Get the current process

        if not process.finished and process.arrival_time <= current_time:  # Check if the process is ready and not finished
            response_ratio = process.calculate_response_ratio(current_time)  # Calculate response ratio

            if response_ratio > max_response_ratio:  # If the response ratio is higher than the current maximum
                max_response_ratio = response_ratio  # Update maximum response ratio
                max_index = i  # Update index of the process with the maximum response ratio

    return max_index  # Return the index of the process with the maximum response ratio

if __name__ == "__main__":
    # Read number of processes from user input
    no_of_processes = int(input())

    # Initialize arrays for process names, arrival times, and burst times
    process_names = [input() for _ in range(no_of_processes)]
    arrival_times = [int(input()) for _ in range(no_of_processes)]
    burst_times = [int(input()) for _ in range(no_of_processes)]

    # Calculate turnaround times
    turn_around_times = calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes)

    # Calculate waiting times
    waiting_times = calculate_waiting_time(turn_around_times, burst_times)

    # Print process information with waiting and turnaround times
    print("Process WaitingTime TurnAroundTime")
    for name, waiting_time, turn_around_time in zip(process_names, waiting_times, turn_around_times):
        print(f"{name} {waiting_time} {turn_around_time}")

